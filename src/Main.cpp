#include "Main.hpp"
#include "cell.hpp"
#include "vector"
#include <random>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int cols, rows;
int w = 20;
vector<Cell *> grid;
Cell *current;
int i = 0;
int width = 600;
int height = 600;
stack<Cell *> s;

Cell *checkNeighbors(Cell *cell);
int index(int i, int j);
int pickRandom(int i, int j);
void removeWalls(Cell *next, Cell *current);

Cell *checkNeighbors(Cell *cell)
{
	vector<Cell *> neighbors;

	Cell *top = NULL;
	Cell *right = NULL;
	Cell *bottom = NULL;
	Cell *left = NULL;

	int indexTop = index(cell->i, cell->j - 1);
	if (indexTop != -1)
		top = grid.at(indexTop);

	int indexRight = index(cell->i + 1, cell->j);
	if (indexRight != -1)
		right = grid.at(indexRight);

	int indexBottom = index(cell->i, cell->j + 1);
	if (indexBottom != -1)
		bottom = grid.at(indexBottom);

	int indexLeft = index(cell->i - 1, cell->j);
	if (indexLeft != -1)
		left = grid.at(indexLeft);

	if (top != NULL && !top->visited)
	{
		neighbors.push_back(top);
	}

	if (right != NULL && !right->visited)
	{
		neighbors.push_back(right);
	}

	if (bottom != NULL && !bottom->visited)
	{
		neighbors.push_back(bottom);
	}

	if (left != NULL && !left->visited)
	{
		neighbors.push_back(left);
	}

	if (neighbors.size() > 0)
	{
		int r = floor(pickRandom(0, neighbors.size()));
		return neighbors[r];
	}
	else
	{
		return NULL;
	}
}

int index(int i, int j)
{
	if (i < 0 || j < 0 || i > cols - 1 || j > rows - 1)
		return -1;

	return i + j * cols;
}
int pickRandom(int i, int j)
{
	srand(time(NULL));
	return rand() % j + i;
}

void removeWalls(Cell *a, Cell *b)
{
	int x = a->i - b->i;
	if (x == 1)
	{
		a->walls[3] = false;
		b->walls[1] = false;
	}
	else if (x == -1)
	{
		a->walls[1] = false;
		b->walls[3] = false;
	}

	int y = a->j - b->j;
	if (y == 1)
	{
		a->walls[0] = false;
		b->walls[2] = false;
	}
	else if (y == -1)
	{
		a->walls[2] = false;
		b->walls[0] = false;
	}
}

int main()
{
#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");
#ifdef SFML_SYSTEM_WINDOWS
	__windowsHelper.setIcon(window.getSystemHandle());
#endif
	// sf::Texture shapeTexture;
	// shapeTexture.loadFromFile("content/sfml.png");
	// shape.setTexture(&shapeTexture);
	cols = floor(width / w);
	rows = floor(height / w);
	for (int j = 0; j < rows; j++)
	{
		for (int i = 0; i < cols; i++)
		{
			Cell *cell = new Cell(i, j, w);
			grid.push_back(cell);
		}
	}

	current = grid[0];

	sf::Event event;

	while (window.isOpen())
	{
		window.clear();
		window.setFramerateLimit(15);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		current->visited = true;
		current->highlight = true;

		Cell *next = checkNeighbors(current);
		if (next != NULL)
		{
			next->visited = true;
			next->highlight = false;

			//STEP 2
			s.push(current);

			//STEP 3
			removeWalls(next, current);

			current = next;
		}
		else if (s.size() > 0)
		{
			current = s.top();
			s.pop();
			current->highlight = false;
		}

		for (auto &&i : grid)
		{
			i->Draw();
			window.draw(i->rect);
			window.draw(i->rectFilled);
		}
		window.display();
	}

	return 0;
}
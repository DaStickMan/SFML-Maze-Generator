
class Cell
{
public:
	int x;
	int y;
	int w;
	int i;
	int j;
	sf::VertexArray rect;
	sf::RectangleShape rectFilled;
	bool walls[4] = {true, true, true, true};
	bool visited = false;
	bool highlight = false;

	Cell(int x1, int y1, int w1)
	{
		w = w1;
		i = x1;
		j = y1;
		x = x1 * w;
		y = y1 * w;
		rect = sf::VertexArray(sf::Lines, 8);
	}

	void Draw()
	{
		rectFilled.setSize(sf::Vector2f(w - .5f, w - .5f));
		rectFilled.setPosition(sf::Vector2f(x + 0.5f, y + 0.5f));

		if (walls[0])
		{
			rect[0].position = sf::Vector2f(x, y);
			rect[1].position = sf::Vector2f(x + w, y);
		}
		else
		{
			rect[0].color = sf::Color(129, 31, 130, 255);
			rect[1].color = sf::Color(129, 31, 130, 255);
		}

		if (walls[1])
		{
			rect[2].position = sf::Vector2f(x + w, y);
			rect[3].position = sf::Vector2f(x + w, y + w);
		}
		else
		{
			rect[2].color = sf::Color(129, 31, 130, 255);
			rect[3].color = sf::Color(129, 31, 130, 255);
		}

		if (walls[2])
		{
			rect[4].position = sf::Vector2f(x + w, y + w);
			rect[5].position = sf::Vector2f(x, y + w);
		}
		else
		{
			rect[4].color = sf::Color(129, 31, 130, 255);
			rect[5].color = sf::Color(129, 31, 130, 255);
		}

		if (walls[3])
		{
			rect[6].position = sf::Vector2f(x, y + w);
			rect[7].position = sf::Vector2f(x, y);
		}
		else
		{
			rect[6].color = sf::Color(129, 31, 130, 255);
			rect[7].color = sf::Color(129, 31, 130, 255);
		}

		rectFilled.setFillColor(sf::Color(0, 0, 0));

		if (visited)
		{
			if (highlight)
			{
				rectFilled.setFillColor(sf::Color(129, 31, 130));
			}
			else
			{
				rectFilled.setFillColor(sf::Color(80, 18, 179));
			}
		}
	}
};

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
		if (walls[0])
		{
			rect[0].position = sf::Vector2f(x, y);
			rect[1].position = sf::Vector2f(x + w, y);
		}
		if (walls[1])
		{
			rect[2].position = sf::Vector2f(x + w, y);
			rect[3].position = sf::Vector2f(x + w, y + w);
		}

		if (walls[2])
		{
			rect[4].position = sf::Vector2f(x + w, y + w);
			rect[5].position = sf::Vector2f(x, y + w);
		}

		if (walls[3])
		{
			rect[6].position = sf::Vector2f(x, y + w);
			rect[7].position = sf::Vector2f(x, y);
		}

		if (visited)
		{
			rectFilled.setSize(sf::Vector2f(w, w));
			rectFilled.setPosition(sf::Vector2f(x, y));
			rectFilled.setFillColor(sf::Color::Magenta);
			rectFilled.setOutlineThickness(0);
		}
		// else
		// {
		// 	rectFilled.setFillColor(sf::Color::Black);
		// }
	}

	~Cell()
	{
		delete this;
	}
};
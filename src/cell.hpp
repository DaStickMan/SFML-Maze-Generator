
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

	void Draw();
};
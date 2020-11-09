
class Cell 
{
	public :
	Cell(int x, int y);
	Cell();

	int m_x;
	int m_y;
	int m_nb_neighb = 0;
	Cell **m_neighb = nullptr;
	bool m_displayed = false;

	void add_neighb(Cell *c);
	void add_neighb(Cell *c1, Cell *c2);
};
#include "Cell.h"

Cell::Cell(int x, int y) : m_x(x), m_y(y)
{

}
Cell::Cell()
{

}

void Cell::add_neighb(Cell *c)
{
	bool pas_dedans=true;

	for (int i=0 ; i<m_nb_neighb ; i++)
	{
		if ((m_neighb[i]=c))
		{
			pas_dedans=false;
		}
	}

	if (pas_dedans)
	{
		
		
		Cell **T=new Cell*[m_nb_neighb+1];

		for (int i=0 ; i<m_nb_neighb ; i++)
		{
			T[i]=m_neighb[i];
		}
		
		T[m_nb_neighb]=c;

		m_nb_neighb+=1;

		delete [] m_neighb;

		m_neighb=new Cell*[m_nb_neighb];

		for (int i=0 ; i<m_nb_neighb ; i++)
		{
			m_neighb[i]=T[i];
		}

		delete [] T;

		c->add_neighb(this);
		
	}
	
}

void Cell::add_neighb(Cell *c1, Cell *c2)
{
	add_neighb(c1);
	add_neighb(c2);
}
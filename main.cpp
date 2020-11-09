#include "Cell.h"
#include <stdlib.h>
#include "vibes.h"
#include <iostream>

using namespace std;

struct Maze
{
	Cell* start;
	Cell* stop;
	

};

void draw_gate(const Cell *n1, const Cell *n2) //efface le mur qu'il y a entre deucx cellules 
{
	vibes::drawBox(min(n1->m_x, n2->m_x) + 0.1, max(n1->m_x, n2->m_x) + 0.9,
		min(n1->m_y, n2->m_y) + 0.1, max(n1->m_y, n2->m_y) + 0.9,
		"lightGray[lightGray]");
}

void display_graph(Cell *cell) // Dessine une cellule puis parcours tous 
							   // les voisins de cette cellule et les dessine.
{
	vibes::drawBox(cell->m_x, cell->m_x + 1, cell->m_y, cell->m_y + 1, "[lightGray]");
	
	cell->m_displayed = true;

	for(int i = 0 ; i < cell->m_nb_neighb ; i++)
	{
		if(!cell->m_neighb[i]->m_displayed)
			display_graph(cell->m_neighb[i]);
		draw_gate(cell, cell->m_neighb[i]);
	}
}


Maze create_maze()
{
	Maze maze;
	Cell *cells[4][4];

	for (int i=0 ; i<4 ; i++)
	{
		

		for (int j=0 ; j<4 ; j++)
		{
			
			cells[i][j]= new Cell(i, j);
			
		}
	}

	int Liens[15][2]={0,1,1,5,5,6,6,2,2,3,3,7,7,11,11,15,15,14,14,13,13,12,10,9,9,5,0,4,4,8};

	for (int i ; i<15 ; i++)
	{
		cells[Liens[i][0]/4][Liens[i][0]%4]->add_neighb(cells[Liens[i][1]/4][Liens[i][1]%4]);
	}

	for (int i=0 ; i<4 ; i++)
	{
		

		for (int j=0 ; j<4 ; j++)
		{
			
			cout << cells[i][j]->m_nb_neighb << endl;
		}
	}

	maze.start = cells[0][2];
	maze.stop = cells[0][3];
	return maze;

}

void display(Maze m)
{
	vibes::beginDrawing(); // initialisation de VIBes
	vibes::newFigure("Maze"); // creation d'une figure
	vibes::setFigureProperties("Maze",
	vibesParams("x", 100, "y", 100,"width", 400, "height", 400)); // proprietes de la figure
	vibes::axisLimits(0-0.5, 4+0.5, 0-0.5, 4+0.5);
	
	display_graph(m.stop);
	
}

int main()
{
	
	Maze m=create_maze();

	display(m);

	return EXIT_SUCCESS;
}
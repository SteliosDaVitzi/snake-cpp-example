#include "Grid.h"
#include "Cell.h"
#include <iostream>
#include <string>
using namespace std;

Grid::Grid(int& rows, int& columns)
{
	totalRows_ = rows;
	totalColumns_ = columns;

	cout << totalRows_ << " " << totalColumns_ << endl;

	GenerateGrid();
}

Grid::~Grid()
{
	for(const Cell* cell : cells_)
	{
		delete cell;
		cell = nullptr;
	}
}


void Grid::GenerateGrid()
{
	for(int i = 0;i < totalRows_;i++)
	{
		for (int j = 0; j < totalColumns_; j++)
		{
			Cell* cell = new Cell(i, j);
			cells_.push_back(cell);
			cout << string("Cell created with row ").append(to_string(i)).append(", and column ").append(to_string(j)) << endl;
		}
	}
}
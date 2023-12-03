#pragma once

#include <list>

#include "Renderer.h"
using namespace std;

class Cell;

class Grid
{
public:
	Grid(int& rows, int& columns, Renderer* renderer);
	~Grid();
	void GenerateGrid();
	Cell* GetCenterCell();
	Cell* GetCellByCoordinates(const int& row, const int& column);
	int GetTotalRows();
	int GetTotalColumns();
	void Render();
	list<Cell*> GetCells();
private:
	Renderer* renderer_;
	int totalRows_;
	int totalColumns_;
	list<Cell*> cells_;
};

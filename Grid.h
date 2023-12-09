#pragma once

#include <list>

#include "IConsumablesGenerator.h"
#include "Renderer.h"
using namespace std;

class Cell;

class Grid
{
public:
	Grid(int& rows, int& columns, Renderer* renderer, IConsumablesGenerator* consumablesGenerator);
	~Grid();
	void GenerateGrid();
	Cell* GetCenterCell();
	Cell* GetCellByCoordinates(const int& row, const int& column);
	int GetTotalRows();
	int GetTotalColumns();
	void Render();
	void GenerateConsumableAtRandomCell();
	list<Cell*> GetCells();
private:
	IConsumablesGenerator* consumablesGenerator_;
	Renderer* renderer_;
	int totalRows_;
	int totalColumns_;
	list<Cell*> cells_;
};

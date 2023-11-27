#pragma once

#include "Cell.h"
#include <list>
using namespace std;

class Grid
{
public:
	Grid(int& rows, int& columns);
	~Grid();
	void GenerateGrid();
private:
	int totalRows_;
	int totalColumns_;
	list<Cell*> cells_;
};

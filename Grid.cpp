#include "Grid.h"
#include "Cell.h"
#include <iostream>
#include <string>

#include "VisualComponents.h"
using namespace std;

Grid::Grid(int& rows, int& columns, Renderer* renderer)
{
	renderer_ = renderer;

	totalRows_ = rows;
	totalColumns_ = columns;

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
	const float totalWidth = totalColumns_ * (10 + 3) - 3;
	const float totalHeight = -totalRows_ * (10 + 3) - 3;

	const float startX = (renderer_->screenWidth - totalWidth) / 2;
	const float startY = (renderer_->screenHeight - totalHeight) / 2;

	for(int i = 0;i < totalRows_;i++)
	{
		for (int j = 0; j < totalColumns_; j++)
		{
			auto cell = new Cell(i, j);
			cell->color = { 255.0f, 255.0f, 255.0f, 255.0f };
			cell->rect.position.X = { startX + j * (10 + 3) };
			cell->rect.position.Y = { startY - i * (10 + 3) };
			cells_.push_back(cell);
		}
	}
}

Cell* Grid::GetCenterCell()
{
	return GetCellByCoordinates(totalRows_/2, totalColumns_/2);
}

Cell* Grid::GetCellByCoordinates(const int& row, const int& column)
{
	Cell* targetCell = nullptr;

	for (Cell* cell : cells_)
	{
		if(cell->GetRow() == row && cell->GetColumn() == column)
		{
			targetCell = cell;
		}
	}

	return targetCell;
}

int Grid::GetTotalRows()
{
	return totalRows_;
}

int Grid::GetTotalColumns()
{
	return totalColumns_;
}

void Grid::Render()
{
	for (const auto cell : cells_) {
		if(cell->GetSnakeSegment() == nullptr)
			renderer_->RenderObject(&cell->rect, &cell->color);
	}
}

list<Cell*> Grid::GetCells()
{
	return cells_;
}

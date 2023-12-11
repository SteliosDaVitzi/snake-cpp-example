#include "Grid.h"
#include "Cell.h"
#include <iostream>
#include <string>
#include "VisualComponents.h"
#include "Utils.h"
#include <random>
using namespace std;

Grid::Grid(int& rows, int& columns, Renderer* renderer, IConsumablesGenerator* consumablesGenerator)
{
	renderer_ = renderer;
	consumablesGenerator_ = consumablesGenerator;
	totalRows_ = rows;
	totalColumns_ = columns;

	GenerateGrid();
	GenerateConsumableAtRandomCell();
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
	const float totalWidth = totalColumns_ * (10.0f + 3.0f) - 3.0f;
	const float totalHeight = -totalRows_ * (10.0f + 3.0f) - 3.0f;

	const float startX = (renderer_->screen_width - totalWidth) / 2.0f;
	const float startY = (renderer_->screen_height - totalHeight) / 2.0f;

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

void Grid::GenerateConsumableAtRandomCell()
{
	const int randomCellIndex = Utils::getRandomInteger(0, totalRows_ * totalColumns_);
	auto it = cells_.begin();
	advance(it, randomCellIndex);

	Cell* targetCell = *it;

	if(targetCell->GetSnakeSegment() != nullptr)
	{
		GenerateConsumableAtRandomCell();
		return;
	}

	IConsumable* consumable = consumablesGenerator_->getConsumable();
	consumable->rect = targetCell->rect;
	consumable->color = { 0.0f, 255.0f, 0.0f, 255.0f };

	targetCell->SetConsumable(consumable);
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
		if(cell->GetSnakeSegment() == nullptr && cell->GetConsumable() == nullptr)
			renderer_->RenderObject(&cell->rect, &cell->color);
		else if(cell->GetConsumable() != nullptr && cell->GetSnakeSegment() == nullptr)
			renderer_->RenderObject(&cell->GetConsumable()->rect, &cell->GetConsumable()->color);
	}
}

list<Cell*> Grid::GetCells()
{
	return cells_;
}

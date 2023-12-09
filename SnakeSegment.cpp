#include "SnakeSegment.h"
#include "Renderer.h"
#include "VisualComponents.h"
#include "Grid.h"
#include "Cell.h"

#include <iostream>
using namespace std;

SnakeSegment::SnakeSegment(int row, int column, Renderer* renderer, Grid* grid, int index)
{
    grid_ = grid;
    renderer_ = renderer;

	currentRow_ = row;
	currentColumn_ = column;

	previousRow_ = currentRow_;
	previousColumn_ = currentColumn_;

    color = { 100.0f, 100.0f, 100.0f, 255.0f };

    index = index;
    /*if(index == 1)
        color = { 0.0f, 0.0f, 255.0f, 255.0f };
    else if(index == 2)
        color = { 0.0f, 255.0f, 0.0f, 255.0f };
    else if (index == 3)
        color = { 255.0f, 0.0f, 0.0f, 255.0f };
    else if (index == 4)
        color = { 0.0f, 255.0f, 255.0f, 255.0f };
    else if (index == 5)
        color = { 255.0f, 255.0f, 0.0f, 255.0f };*/

    //cout << "Segment with index : " << index << ", placed to : " << currentRow_ << "," << currentColumn_ << endl;

    rect = grid_->GetCellByCoordinates(currentRow_, currentColumn_)->rect;
}

SnakeSegment::~SnakeSegment()
{

}


void SnakeSegment::UpdatePosition(bool isHead, MoveDirection moveDirection, SnakeSegment* nextSegment)
{
    previousRow_ = currentRow_;
    previousColumn_ = currentColumn_;

    if (isHead)
    {
        switch (moveDirection)
        {
        case Up:
            if (currentRow_ + 1 < grid_->GetTotalRows())
                currentRow_++;
            else
                currentRow_ = 0;
            break;
        case Down:
            if (currentRow_ - 1 >= 0)
                currentRow_--;
            else
                currentRow_ = grid_->GetTotalRows() - 1;
            break;
        case Left:
            if (currentColumn_ - 1 >= 0)
                currentColumn_--;
            else
                currentColumn_ = grid_->GetTotalColumns() - 1;
            break;
        case Right:
            if (currentColumn_ + 1 < grid_->GetTotalColumns())
                currentColumn_++;
            else
                currentColumn_ = 0;
            break;
        }
        UpdateGridSnakeSegment();

        return;
    }

    if (!nextSegment)
        return;

    currentRow_ = nextSegment->PreviousRow();
    currentColumn_ = nextSegment->PreviousColumn();

    UpdateGridSnakeSegment();
}

void SnakeSegment::UpdateGridSnakeSegment()
{
    const auto currentCell = grid_->GetCellByCoordinates(currentRow_, currentColumn_);
    const auto previousCell = grid_->GetCellByCoordinates(previousRow_, previousColumn_);

    currentCell->SetSnakeSegment(this);
    previousCell->SetSnakeSegment(nullptr);

    rect = currentCell->rect;
}

int SnakeSegment::CurrentRow()
{
    return currentRow_;
}

int SnakeSegment::CurrentColumn()
{
    return currentColumn_;
}

int SnakeSegment::PreviousRow()
{
    return previousRow_;
}

int SnakeSegment::PreviousColumn()
{
    return previousColumn_;
}

void SnakeSegment::Render()
{
    renderer_->RenderObject(&rect, &color);
}


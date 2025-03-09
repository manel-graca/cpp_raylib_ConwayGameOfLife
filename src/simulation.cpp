#include "simulation.hpp"

#include <raylib.h>

#include "grid.hpp"

void Simulation::Draw() { grid.Draw(); }

void Simulation::SetCellValue(int row, int column, int value)
{
    grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbours(int row, int column)
{
    int liveNeighbours = 0;
    std::vector<std::pair<int, int>>
        neighbourOffsets = {
            {-1, 0},  // North
            {1, 0},   // South
            {0, -1},  // West
            {0, 1},   // East
            {-1, -1}, // NorthWest
            {-1, 1},  // NorthEast
            {1, -1},  // SouthWest
            {1, 1}    // SouthEast
        };

    for (std::pair<int, int> offset : neighbourOffsets)

    {
        int neighbourRow = (row + offset.first + grid.GetRows()) % grid.GetRows();
        int neighbourColumn = (column + offset.second + grid.GetColumns()) % grid.GetColumns();
        liveNeighbours += grid.GetValue(neighbourRow, neighbourColumn);
    }

    return liveNeighbours;
}

void Simulation::Update()
{
    if (!IsRunning())
    {
        return;
    }

    for (int row = 0; row < grid.GetRows(); row++)
    {
        for (int column = 0; column < grid.GetColumns(); column++)
        {
            int liveNeighbours = CountLiveNeighbours(row, column);
            int cellValue = grid.GetValue(row, column);

            if (cellValue == 1)
            {
                if (liveNeighbours > 3 || liveNeighbours < 2)
                {
                    tempGrid.SetValue(row, column, 0);
                }
                else
                {
                    tempGrid.SetValue(row, column, 1);
                }
            }
            else
            {
                if (liveNeighbours == 3)
                {
                    tempGrid.SetValue(row, column, 1);
                }
                else
                {
                    tempGrid.SetValue(row, column, 0);
                }
            }
        }
    }
    grid = tempGrid;
}

void Simulation::ClearGrid()
{
    if (!IsRunning())
    {
        grid.ClearGrid();
    }
}

void Simulation::CreateRandomState()
{
    if (!IsRunning())
    {
        grid.FillRandom();
    }
}

void Simulation::ToggleCell(int row, int column)
{
    if (!IsRunning())
    {
        grid.ToggleCell(row, column);
    }
}

#include <raylib.h>
#include "simulation.hpp"

int main()
{
    Color GREY = {29, 29, 29, 255};
    const int WINDOW_WIDTH = 1200;
    const int WINDOW_HEIGHT = 900;
    const int CELL_SIZE = 6;
    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Conway Game of Life");
    SetTargetFPS(FPS);

    Simulation simulation = Simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    while (!WindowShouldClose())
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            Vector2 mousePos = GetMousePosition();
            int row = mousePos.y / CELL_SIZE;
            int column = mousePos.x / CELL_SIZE;
            simulation.ToggleCell(row, column);
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            if (simulation.IsRunning())
            {
                simulation.Stop();
            }
            else
            {
                simulation.Start();
            }
        }
        else if (IsKeyPressed(KEY_R))
        {
            simulation.CreateRandomState();
        }
        else if (IsKeyPressed(KEY_C))
        {
            simulation.ClearGrid();
        }

        simulation.Update();

        BeginDrawing();
        ClearBackground(GREY);

        simulation.Draw();

        EndDrawing();
    }

    CloseWindow();
}

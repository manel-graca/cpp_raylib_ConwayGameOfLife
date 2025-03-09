#include <raylib.h>
#include "simulation.hpp"

int main()
{
    Color GREY = {29, 29, 29, 255};
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 25;
    int FPS = 16;

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

        if (!simulation.IsRunning())
        {
            DrawText("Paused", 10, 10, 30, WHITE);
        }

        EndDrawing();
    }

    CloseWindow();
}

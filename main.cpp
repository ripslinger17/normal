#include "raylib.h"

typedef enum GameScreen{ WLC = 0, S1, S2} GameScreen;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;


    InitWindow(screenWidth,screenHeight,"Welcome Window");
    GameScreen currentScreen = WLC;

    int framesCounter = 0;
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        switch (currentScreen) {
            case WLC: {
                framesCounter++;
                if (framesCounter > 300) {
                    currentScreen = S1;
                }
            } break;
            case S1:{
                if (IsKeyPressed(KEY_ONE))
                {
                    currentScreen = S2;
                }
                break;
            }
            case S2:
            {
                if(IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = S1;
                }
            }
                break;
            default:
                break;
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        switch (currentScreen) {
            case WLC: {
                DrawRectangle(0,0,screenWidth,screenHeight,WHITE);
                DrawText("MAIN SCREEN", 200, 10, 60, BLACK);
                DrawText("WELCOME", 360, 200, 20, BLUE);
                DrawText("TO", 395, 220, 20, BLUE);
                DrawText("SHREE SWAMINARAYAN INSTITUTE OF TECHNOLOGY", 140, 240, 20, BLUE);
            }
                break;
            case S1:
            {
                DrawRectangle(0,0,screenWidth,screenHeight,WHITE);
                DrawText("PRESS 1 to get Admission Information", 120, 220, 20, DARKGREEN);
                DrawText("PRESS ESC to EXIT", 120, 240, 20, DARKGREEN);
            }
                break;
            case S2:
            {
                DrawRectangle(0,0,screenWidth,screenHeight,WHITE);
                DrawText("For admission contact XYZ Professors", 120, 200, 20, DARKGREEN);
                DrawText("Contact Number : 1234567890", 120, 220, 20, DARKGREEN);
                DrawText("PRESS ENTER to return to Main Screen", 300, 400, 12, DARKGREEN);
            }
                break;
            default:
                break;
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
#include "raylib.h"

#define SCREEN_WIDTH (1920)
#define SCREEN_HEIGHT (1080)
#define SCALE 1//(0.666f)

#define ASSET_PATH "../assets/"

void draw_texture(Texture texture, int x, int y, int w, int h, Color color)
{
    DrawTexturePro(texture, (Rectangle) { 0, 0, texture.width, texture.height },
            (Rectangle) { x, y, w, h }, (Vector2){0}, 0, color);
}

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Waves 2k15 + sqrt(4)");

    Texture2D arena = LoadTexture(ASSET_PATH"arena.png");
    Texture2D chair = LoadTexture(ASSET_PATH"chair_blue.png");

    Texture2D guy_down = LoadTexture(ASSET_PATH"pirate_down.png");
    Texture2D guy_rising = LoadTexture(ASSET_PATH"pirate_rising.png");
    Texture2D guy_up = LoadTexture(ASSET_PATH"pirate_up.png");

    Texture2D player_down = LoadTexture(ASSET_PATH"vasile_down.png");
    Texture2D player_rising = LoadTexture(ASSET_PATH"vasile_rising.png");
    Texture2D player_up = LoadTexture(ASSET_PATH"vasile_up.png");

    int guy_w = guy_down.width * SCALE;
    int guy_h = guy_down.height * SCALE;

    int arena_padd_x =  62 * SCALE;
    int arena_padd_y = 125 * SCALE;

    int chair_padd_x = 11 * SCALE;
    int chair_padd_y = 11 * SCALE;

    int chair_w = chair.width  * SCALE;
    int chair_h = chair.height * SCALE;

    int cols_count = (SCREEN_WIDTH  - arena_padd_x * 2) / (chair_w + chair_padd_x);
    int rows_count = (SCREEN_HEIGHT - arena_padd_y * 2) / (chair_h + chair_padd_y);

    int chair_start_x = (SCREEN_WIDTH  / 2) - (((chair_w + chair_padd_x) * cols_count) / 2);
    int chair_start_y = (SCREEN_HEIGHT / 2) - (((chair_h + chair_padd_y) * rows_count) / 2);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        draw_texture(arena, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);

        for (int i = 0; i < rows_count; i++)
        {
            for (int j = 0; j < cols_count; j++)
            {
                int chair_x = chair_start_x + (chair_w + chair_padd_x) * j;
                int chair_y = chair_start_y + (chair_h + chair_padd_y) * i;

                int guy_x = chair_x + ((chair_w + chair_padd_x) / 2) - guy_w / 2;
                int guy_y = chair_y + ((chair_h + chair_padd_y) / 2) - guy_h / 2;

                draw_texture(chair, chair_x, chair_y, chair_w, chair_h, GRAY);

                if (i == rows_count / 2 && j == cols_count / 2)
                {
                    draw_texture(player_down, guy_x, guy_y, guy_w, guy_h, WHITE);
                }
                else
                {
                    draw_texture(guy_down, guy_x, guy_y, guy_w, guy_h, GRAY);
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
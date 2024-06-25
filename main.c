#include <raylib.h>
#include <stdio.h>
#include <math.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define CHAR_SIZE 8

Vector2 ConvertCharToCoords(char c) {
	int y = floor(c / 16);
	int x = c % 16;
	Vector2 v = {
		.x = x, .y = y,
	};
	return v;
}	

void DrawBitmapCharacter(Texture2D texture, char ch, Vector2 pos, Color c) {
	Vector2 coords = ConvertCharToCoords(ch);
	Rectangle rect = {
		coords.x * CHAR_SIZE,
		coords.y * CHAR_SIZE,
		CHAR_SIZE, CHAR_SIZE
	};
	DrawTextureRec(texture, rect, pos, c);
}

int main() {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib [core] example - basic window");
	Texture2D bitmap = LoadTexture("assets/glyphs.png");
	Vector2 pos = { .x = 0, .y = 0, };

    while (!WindowShouldClose()) {
        BeginDrawing();

			DrawBitmapCharacter(bitmap, 'A', pos, WHITE);
            ClearBackground(BLACK);

        EndDrawing();
    }

	UnloadTexture(bitmap);
    CloseWindow();
    return 0;
}

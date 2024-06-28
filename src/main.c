#include <raylib.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include <stdio.h>
#include <math.h>

#include "mylua.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define CHAR_SIZE 8

Vector2 ConvertCharToCoords(char c) {
	int x = c % 16;
	int y = floor(c / 16);

	Vector2 coords = { x, y };
	return coords;
}

void DrawBitmapCharacter(Texture2D texture, int character, Vector2 pos, Color color) {
	Vector2 coords = ConvertCharToCoords(character);
	Rectangle rect = {
		coords.x * CHAR_SIZE, coords.y * CHAR_SIZE, CHAR_SIZE, CHAR_SIZE
	};
	pos.x *= CHAR_SIZE;
	pos.y *= CHAR_SIZE;
	DrawTextureRec(texture, rect, pos, color);
}

int main() {
	int x = 0;
	int y = 0;
	Vector2 pos;

	// initialize game
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Microgue");
	Texture2D bitmap = LoadTexture("assets/glyphs.png");

	// initialize new lua state
	lua_State* L = luaL_newstate();

	while (!WindowShouldClose()) {
		// input
		if (IsKeyPressed(KEY_LEFT)) x--;
		else if (IsKeyPressed(KEY_RIGHT)) x++;
		else if (IsKeyPressed(KEY_UP)) y--;
		else if (IsKeyPressed(KEY_DOWN)) y++;

		BeginDrawing();

			pos = (Vector2){ x /*CHAR_SIZE*/, y /* CHAR_SIZE*/ };
			DrawBitmapCharacter(bitmap, (int)('A'), pos, WHITE);
			ClearBackground(BLACK);

		EndDrawing();
	}

	// de-init lua
	lua_close(L);

	// de-init game
	UnloadTexture(bitmap);
	CloseWindow();
	return 0;
}


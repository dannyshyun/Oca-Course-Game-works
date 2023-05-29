#pragma once

#define SCREEN_W 1280
#define SCREEN_H 720

#define COLOR_WHITE GetColor(255, 255, 255)
#define COLOR_YELLOW GetColor(255, 255, 0)

#define COLOR_PLAYER GetColor(128, 128, 255)
#define COLOR_NPC GetColor(255, 128, 128)

#define RED GetColor(255, 0, 0)
#define GREEN GetColor(0, 255, 0)
#define BLUE GetColor(0, 0, 255)
#define GRAY GetColor(200, 200, 200)
#define BLACK GetColor(0, 0, 0)
#define WHITE GetColor(255, 255, 255)

#define DELTA_TIME 1.f / 60.f

void GameInit();   //	‰Šú‰»ˆ—
void GameUpdate(); //	XVˆ—
void GameRender(); //	•`‰æˆ—
void GameExit();   //	I—¹ˆ—

enum GAME_MODE
{
    GAME_TITLE = 0,
    GAME_PRE_COUNT,
    GAME_START,
    GAME_CLEAR,
    GAME_RESULT,

    MODE_MAX
};
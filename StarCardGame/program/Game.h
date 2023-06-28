#pragma once

#define SCREEN_FRAME  60

#define SCREEN_W     1280
#define SCREEN_H     720

#define WHITE        GetColor( 255, 255, 255 )
#define YELLOW       GetColor( 255, 255, 0 )

#define COLOR_PLAYER GetColor( 128, 128, 255 )
#define COLOR_NPC    GetColor( 255, 128, 128 )

void GameInit();    //	‰Šú‰»ˆ—
void GameUpdate();  //	XVˆ—
void GameRender();  //	•`‰æˆ—
void GameExit();    //	I—¹ˆ—

enum GAME_TURN
{
    LOAD_TURN = 0,
    SHUFFLE_TURN,
    DEAL_TURN,
    MOVE_TURN,
    PLAYER_ATTACK_TURN,
    PLAYER_DEFENSE_TURN,
    NPC_ATTACK_TURN,
    NPC_DEFESE_TURN,
    RESULT_TURN,

    TURN_MAX
};

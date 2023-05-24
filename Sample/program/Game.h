#pragma once

#define SCREEN_W	800
#define SCREEN_H	450

#define COLOR_WHITE		GetColor( 255, 255, 255 )
#define COLOR_YELLOW	GetColor( 255, 255,   0 )

#define COLOR_PLAYER	GetColor( 128, 128, 255 )
#define COLOR_NPC		GetColor( 255, 128, 128 )

#define RED             GetColor( 255, 0, 0)
#define GREEN           GetColor(0, 255, 0)

#define DELTA_TIME      1.f / 60.f

void GameInit();	//	����������
void GameUpdate();	//	�X�V����
void GameRender();	//	�`�揈��
void GameExit();	//	�I������

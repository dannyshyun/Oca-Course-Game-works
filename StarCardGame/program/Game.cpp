#include "Main.h"
#include "Game.h"
#include "Hit.h"

#include "Camera.h"
#include "Ground.h"
#include "Player.h"
#include "Npc.h"

#include "Base.h"
#include "CardBase.h"
#include "ActionCard.h"
#include "Environment.h"
#include "ItemCard.h"
//	���f���f�[�^
int ground_model;
int player_model;
int npc_model;
//	�N���X�錾
Camera	camera;
Ground	ground;
Player	player;
Npc		npc;

//---------------------------------------------------------------------------------
//	����������
//---------------------------------------------------------------------------------
void GameInit()
{
	//	���f���f�[�^�̓ǂݍ���
	ground_model = MV1LoadModel( "data/ground.mqoz" );
	player_model = MV1LoadModel( "data/player.mqoz" );
	npc_model = MV1LoadModel( "data/npc.mqoz" );
	//	�N���X�̏�����
	camera.Init();
	ground.Init( ground_model );
	player.Init( player_model );
	npc.Init( npc_model );
}
//---------------------------------------------------------------------------------
//	�X�V����
//---------------------------------------------------------------------------------
void GameUpdate()
{
	//	�X�V����
	ground.Update();
	//	�`�c�v�L�[�ŉ�]�ƈړ�
	player.Update();
	//	������ς��Ȃ���ړ�
	npc.Update();

	camera.Update();
}
//---------------------------------------------------------------------------------
//	�`�揈��
//---------------------------------------------------------------------------------
void GameRender()
{
	camera.Render();

	ground.Render();
	npc.Render();
	player.Render();

	DrawString( 16, 16, "�`�c�L�[�F�v���C���[��]", GetColor( 255, 255, 255 ) );
	DrawString( 16, 32, "�v�@�L�[�F�v���C���[�ړ�", GetColor( 255, 255, 255 ) );

	DrawString( 16, 64, "�S�̃J�����i�}�E�X�h���b�O�łŃJ�����̌����ύX�j", GetColor( 255, 255, 255 ) );
}
//---------------------------------------------------------------------------------
//	�I������
//---------------------------------------------------------------------------------
void GameExit()
{
	camera.Exit();
	ground.Exit();
	player.Exit();
	npc.Exit();

	MV1DeleteModel( ground_model );
	MV1DeleteModel( player_model );
	MV1DeleteModel( npc_model );
}

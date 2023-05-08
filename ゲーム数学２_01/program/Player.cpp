#include "Main.h"
#include "Game.h"
#include "Player.h"

#define PLAYER_MOV_SPEED 0.1f
#define PLAYER_ROT_SPEED 1.0f

//---------------------------------------------------------------------------------
//	èâä˙âªèàóù
//---------------------------------------------------------------------------------
void Player::Init(int model)
{
	m_model = model;

	m_pos.set(0.0f, 0.0f, -5.0f);
	m_rot.set(0.0f, 0.0f, 0.0f);

	m_radius = 0.5f;
}
//---------------------------------------------------------------------------------
//	çXêVèàóù
//---------------------------------------------------------------------------------
void Player::Update()
{
	Vector3 r_vel = {0.f, 1.f, 0.f};
	if (CheckHitKey(KEY_INPUT_D))
	{
		m_rot.y += PLAYER_ROT_SPEED;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		m_rot.y -= PLAYER_ROT_SPEED;
	}
	m_rot.x = (GetMouseY() - SCREEN_H / 2.f) / SCREEN_H * 90.f;
	m_rot.y = (GetMouseX() - SCREEN_W / 2.f) / SCREEN_W * 90.f;

	if (CheckHitKey(KEY_INPUT_W))
	{
		m_pos.x += PLAYER_MOV_SPEED * sinf(TO_RADIAN(m_rot.y));
		m_pos.z += PLAYER_MOV_SPEED * cosf(TO_RADIAN(m_rot.y));
	}
}
//---------------------------------------------------------------------------------
//	ï`âÊèàóù
//---------------------------------------------------------------------------------
void Player::Render()
{
	MV1SetPosition(m_model, VGet(m_pos.x, m_pos.y, m_pos.z));
	MV1SetRotationXYZ(m_model, VGet(TO_RADIAN(m_rot.x), TO_RADIAN(m_rot.y), TO_RADIAN(m_rot.z)));
	MV1DrawModel(m_model);
}
//---------------------------------------------------------------------------------
//	èIóπèàóù
//---------------------------------------------------------------------------------
void Player::Exit()
{
}

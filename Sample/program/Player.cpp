#include "Main.h"
#include "Game.h"
#include "Player.h"

#define PLAYER_MOV_SPEED 0.1f
#define PLAYER_ROT_SPEED 1.0f
#define POWER_SPEED 5.f

//---------------------------------------------------------------------------------
//	èâä˙âªèàóù
//---------------------------------------------------------------------------------
void Player::Init(int model)
{
	m_model = model;

	m_pos.set(0.0f, 0.0f, -5.0f);
	m_rot.set(0.0f, 0.0f, 0.0f);

	m_radius = 0.5f;

	m_throw_power = 0.f;
}
//---------------------------------------------------------------------------------
//	çXêVèàóù
//---------------------------------------------------------------------------------
void Player::Update()
{
	const float ROLL_SPEED = 90.f / SCREEN_H;
	const float PITCH_SPEED = 90.f / SCREEN_W;
	Vector2 mouse_mov = {
		(GetMouseX() - SCREEN_W / 2), 
		(GetMouseY() - SCREEN_H / 2) 
	};
	m_rot.x += mouse_mov.y * ROLL_SPEED;
	m_rot.y += mouse_mov.x * PITCH_SPEED;

	if (CheckHitKey(KEY_INPUT_W))
	{
		m_pos.x += PLAYER_MOV_SPEED * sinf(TO_RADIAN(m_rot.y));
		m_pos.z += PLAYER_MOV_SPEED * cosf(TO_RADIAN(m_rot.y));
	}

	if (CheckHitKey(KEY_INPUT_S)) {
		m_pos.x += PLAYER_MOV_SPEED * sinf(TO_RADIAN(m_rot.y + 180.f));
		m_pos.z += PLAYER_MOV_SPEED * cosf(TO_RADIAN(m_rot.y + 180.f));
	}

	if (CheckHitKey(KEY_INPUT_D))
	{
		m_pos.x += PLAYER_MOV_SPEED * sinf(TO_RADIAN(m_rot.y + 90.f));
		m_pos.z += PLAYER_MOV_SPEED * cosf(TO_RADIAN(m_rot.y + 90.f));
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		m_pos.x += PLAYER_MOV_SPEED * sinf(TO_RADIAN(m_rot.y - 90.f));
		m_pos.z += PLAYER_MOV_SPEED * cosf(TO_RADIAN(m_rot.y - 90.f));
	}

	
}
//---------------------------------------------------------------------------------
//	ï`âÊèàóù
//---------------------------------------------------------------------------------
void Player::Render()
{
	MV1SetPosition(m_model, VGet(m_pos.x, m_pos.y, m_pos.z));
	MV1SetScale(m_model, VGet(0.02f, 0.02f, 0.02f));
	MV1SetRotationXYZ(m_model, VGet(TO_RADIAN(m_rot.x), TO_RADIAN(m_rot.y ), TO_RADIAN(m_rot.z)));
	MV1DrawModel(m_model);
}
//---------------------------------------------------------------------------------
//	èIóπèàóù
//---------------------------------------------------------------------------------
void Player::Exit()
{
}

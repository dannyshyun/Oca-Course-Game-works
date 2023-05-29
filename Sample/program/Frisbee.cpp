#include "Main.h"
#include "Game.h"
#include "Hit.h"
#include "Frisbee.h"

#define FLY_TIME_MAX 5
#define MOVE_SPEED 0.5f
#define MOV_SPEED 0.5f
#define ROT_SPEED 2.5f

void Frisbee::Init(int model)
{
	m_model = model;
	m_radius = 1.f;
	time_count = 0;
	hit_count = 0;
}

void Frisbee::Update(Vector3 player_pos, Vector3 player_rot, Vector3 hit_coin_pos)
{
	if (CheckMouseInput(MOUSE_INPUT_LEFT) && !isMove)
	{
		posInit(player_pos, player_rot);
	}
	if (isMove && !isLoop)
	{
		m_pos += m_move;
		time_count++;
		if (time_count * DELTA_TIME >= FLY_TIME_MAX)
		{
			isMove = false;
			time_count = 0;
		}
	}
	if (isLoop)
	{
		Loop(hit_coin_pos);
	}
}

void Frisbee::Render()
{
	if (isMove)
	{
		MV1SetPosition(m_model, VGet(m_pos.x, m_pos.y, m_pos.z));
		MV1SetRotationXYZ(m_model, VGet(TO_RADIAN(m_rot.x), TO_RADIAN(m_rot.y), TO_RADIAN(m_rot.z)));
		MV1SetScale(m_model, VGet(0.1f, 0.1f, 0.1f));
		MV1DrawModel(m_model);
		// DrawSphere3D(VGet(m_pos.x, m_pos.y, m_pos.z), m_radius, 32, RED, GREEN, false);
	}
	DrawCircle(SCREEN_W - 30, SCREEN_H - 30, 5, isMove ? RED : GREEN);
}

void Frisbee::Exit()
{
}

bool Frisbee::CheckCoinHit(Coin *coin)
{
	if (isMove && !isLoop && CheckBallHit(m_pos, m_radius, coin->m_pos, coin->m_radius))
	{
		isLoop = true;
		m_rot.y = 90.f;
		return true;
	}
	return false;
}

bool Frisbee::CheckCatch(Vector3 player_pos, float player_radius)
{
	if (isMove && isCatchable && CheckBallHit(m_pos, m_radius, player_pos, player_radius))
	{
		isMove = false;
		return true;
	}
	return false;
}

void Frisbee::Loop(Vector3 coin_pos)
{

	m_rot.y += ROT_SPEED;

	m_pos.x += MOV_SPEED * sinf(TO_RADIAN(m_rot.y));
	m_pos.z += MOV_SPEED * cosf(TO_RADIAN(m_rot.y) * 2) / 2;
	if (m_rot.y >= (90.f + 360.f))
	{
		isLoop = false;
		m_rot.y += GetRand(90) - 45.f;
		m_move *= -1;
	}
	isCatchable = true;
}

void Frisbee::posInit(Vector3 player_pos, Vector3 player_rot)
{
	m_pos.set(player_pos);
	m_pos.y -= 0.5f;
	m_rot.clear();
	m_rot = player_rot;
	m_rot.x = 90.f;
	m_move.clear();
	m_move.x = sinf(TO_RADIAN(m_rot.y));
	m_move.z = cosf(TO_RADIAN(m_rot.y));
	m_move.SetLength(MOVE_SPEED);
	isMove = true;
	time_count = 0;
	isCatchable = false;

	// m_move.y = -player_rot.x * 1.f;
}

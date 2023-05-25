#include "Main.h"
#include "Frisbee.h"
#include "Game.h"

#define FLY_TIME_MAX 5
#define MOVE_SPEED 0.5f

void Frisbee::Init(int model)
{
	m_model = model;
	m_radius = 1.f;
	time_count = 0;
}

void Frisbee::Update(Vector3 player_pos, Vector3 player_rot)
{
	if (CheckMouseInput(MOUSE_INPUT_LEFT) && !isMove)
	{
		posInit(player_pos, player_rot);
	}
	if (isMove)
	{
		m_pos += m_move;
		time_count++;
		if (time_count * DELTA_TIME >= FLY_TIME_MAX)
		{
			isMove = false;
			time_count = 0;
		}
	}
	else
	{
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
		//DrawSphere3D(VGet(m_pos.x, m_pos.y, m_pos.z), m_radius, 32, RED, GREEN, false);
	}
	DrawCircle(770, 420, 5, isMove ? RED : GREEN);
}

void Frisbee::Exit()
{
}

void Frisbee::posInit(Vector3 player_pos, Vector3 player_rot)
{
	m_pos.set(player_pos);
	m_pos.y += 4.5f;
	m_rot.clear();
	m_rot.x = 90.f;
	m_move.clear();
	m_move.x = sinf(TO_RADIAN(player_rot.y));
	m_move.z = cosf(TO_RADIAN(player_rot.y));
	m_move.SetLength(MOVE_SPEED);
	isMove = true;

	// m_move.y = -player_rot.x * 1.f;
}

#include "Main.h"
#include "Frisbee.h"
#include "Game.h"


void Frisbee::Init(int model, Vector3 player_pos, Vector3 player_rot)
{
	m_model = model;
	m_pos.set(player_pos);
	m_pos.y += 3.f;
	m_rot.clear();
	m_rot.x = 90.f;
	m_move.clear();
	m_move.x = sinf(TO_RADIAN(player_rot.y));
	m_move.z = cosf(TO_RADIAN(player_rot.y));
	m_move.SetLength(5.f);
	// m_move.y = -player_rot.x * 1.f;
}

void Frisbee::Update()
{
	m_pos += m_move;
}

void Frisbee::Render()
{
	MV1SetPosition(m_model, VGet(m_pos.x, m_pos.y, m_pos.z));
	MV1SetRotationXYZ(m_model, VGet(TO_RADIAN(m_rot.x), TO_RADIAN(m_rot.y), TO_RADIAN(m_rot.z)));
	MV1DrawModel(m_model);
}

void Frisbee::Exit()
{
}

#include "Main.h"
#include "Game.h"
#include "Random.h"
#include "Npc.h"

#define NPC_MOV_SPEED 0.1f
#define NPC_ROT_SPEED 0.5f

//---------------------------------------------------------------------------------
//	èâä˙âªèàóù
//---------------------------------------------------------------------------------
void Npc::Init(int model)
{
	m_model = model;

	m_rot.x = 90.f;

	m_pos.x = 0.0f;
	m_pos.z = 10.0f;
	m_rot.y = 90.0f;

	m_radius = 1.f;

	loop_rot = 90.f;
}
//---------------------------------------------------------------------------------
//	çXêVèàóù
//---------------------------------------------------------------------------------
void Npc::Update()
{
	m_rot.y += NPC_ROT_SPEED;
	loop_rot += 0.5f;

	m_pos.z += NPC_MOV_SPEED * cosf(TO_RADIAN(loop_rot) * 2) / 2;
	m_pos.x += NPC_MOV_SPEED * sinf(TO_RADIAN(loop_rot));
}
//---------------------------------------------------------------------------------
//	ï`âÊèàóù
//---------------------------------------------------------------------------------
void Npc::Render()
{
	MV1SetPosition(m_model, VGet(m_pos.x, m_pos.y, m_pos.z));
	MV1SetRotationXYZ(m_model, VGet(TO_RADIAN(m_rot.x), TO_RADIAN(m_rot.y), TO_RADIAN(m_rot.z)));
	MV1SetScale(m_model, VGet(0.1f, 0.1f, 0.1f));
	MV1DrawModel(m_model);
	DrawSphere3D(VGet(m_pos.x, m_pos.y, m_pos.z), m_radius, 32, RED, GREEN, false);
	// DrawFormatString(32, 32, GetColor(255, 255, 255), "%d", (int)m_rot.y % 360);
}
//---------------------------------------------------------------------------------
//	èIóπèàóù
//---------------------------------------------------------------------------------
void Npc::Exit()
{
}

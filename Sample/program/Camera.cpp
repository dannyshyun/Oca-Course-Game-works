#include "Main.h"
#include "Game.h"
#include "Camera.h"

#define CAMERA_LENGTH 9.f

//---------------------------------------------------------------------------------
//	èâä˙âªèàóù
//---------------------------------------------------------------------------------
void Camera::Init()
{
	m_pos.set( 0.0f, 5.0f, -30.0f );
	m_look.set( 0.0f, 0.0f, 0.0f );
}
//---------------------------------------------------------------------------------
//	çXêVèàóù
//---------------------------------------------------------------------------------
void Camera::Update(const Vector3 &pos, const Vector3 &rot)
{
	/*Vector3 pos0 = pos;
	pos0.z = pos.z + 5.f * sinf(TO_RADIAN(rot.y));
	pos0.x = pos.x + 5.f * cosf(TO_RADIAN(rot.y));*/

	const float L = 5.f;
	Vector3 pos0 = { 0.f ,0.f, 1.f };
	

	Vector3 pos1;
	pos1.x = pos0.x * cosf(TO_RADIAN(-rot.y)) - pos0.z * sinf(TO_RADIAN(-rot.y));
	pos1.y = pos0.y;
	pos1.z = pos0.z * cosf(TO_RADIAN(-rot.y)) + pos0.x * sinf(TO_RADIAN(-rot.y));

	Vector3 pos2;
	pos2.x = pos1.x * cosf(TO_RADIAN(-rot.z)) + pos1.y * sinf(TO_RADIAN(-rot.z));
	pos2.y = pos1.y * cosf(TO_RADIAN(-rot.z)) - pos1.x * sinf(TO_RADIAN(-rot.z));
	pos2.z = pos1.z;

	Vector3 pos3;
	pos3.x = pos2.x;
	pos3.y = pos2.y * cosf(TO_RADIAN(-rot.x)) + pos2.z * sinf(TO_RADIAN(-rot.x));
	pos3.z = pos2.z * cosf(TO_RADIAN(-rot.x)) - pos2.y * sinf(TO_RADIAN(-rot.x));

	pos3.SetLength(L);
	Vector3 pos_look = pos + pos3;
	m_look.set(pos_look);
	m_look.y += 5.f;

	pos3.SetLength(CAMERA_LENGTH);
	m_pos = pos;
	m_pos.y = 3.f;

	/*float back_rot = rot.y + 180.f;
	m_pos.x = m_look.x + CAMERA_LENGTH * sinf(TO_RADIAN(back_rot));
	m_pos.z = m_look.z + CAMERA_LENGTH * cosf(TO_RADIAN(back_rot));*/
}
//---------------------------------------------------------------------------------
//	ï`âÊèàóù
//---------------------------------------------------------------------------------
void Camera::Render()
{
	SetCameraPositionAndTarget_UpVecY( VGet( m_pos.x, m_pos.y, m_pos.z ), VGet( m_look.x, m_look.y, m_look.z ) );
}
//---------------------------------------------------------------------------------
//	èIóπèàóù
//---------------------------------------------------------------------------------
void Camera::Exit()
{
}

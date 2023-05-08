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
	Vector3 l_pos = pos;
	l_pos.x = pos.x + 5.f * sinf(TO_RADIAN(rot.y));
	l_pos.z = pos.z + 5.f * cosf(TO_RADIAN(rot.y));
	m_look.set(l_pos);

	float back_rot = rot.y + 180.f;
	m_pos.x = m_look.x + CAMERA_LENGTH * sinf(TO_RADIAN(back_rot));
	m_pos.z = m_look.z + CAMERA_LENGTH * cosf(TO_RADIAN(back_rot));
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

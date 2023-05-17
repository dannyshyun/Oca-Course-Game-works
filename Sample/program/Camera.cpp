#include "Main.h"
#include "Game.h"
#include "Camera.h"

#define CAMERA_LENGTH 9.f

//---------------------------------------------------------------------------------
//	èâä˙âªèàóù
//---------------------------------------------------------------------------------
void Camera::Init()
{
	m_pos.set(0.0f, 5.0f, -30.0f);
	m_look.set(0.0f, 0.0f, 0.0f);
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
	// relative vector from player to camera look
	Vector3 vec0 = {0.f, 0.f, 1.f};

	Vector3 vecXZ;
	vecXZ.x = vec0.x * cosf(TO_RADIAN(-rot.y)) - vec0.z * sinf(TO_RADIAN(-rot.y));
	vecXZ.y = vec0.y;
	vecXZ.z = vec0.z * cosf(TO_RADIAN(-rot.y)) + vec0.x * sinf(TO_RADIAN(-rot.y));

	Vector3 vecXY;
	vecXY.x = vecXZ.x * cosf(TO_RADIAN(-rot.z)) + vecXZ.y * sinf(TO_RADIAN(-rot.z));
	vecXY.y = vecXZ.y * cosf(TO_RADIAN(-rot.z)) - vecXZ.x * sinf(TO_RADIAN(-rot.z));
	vecXY.z = vecXZ.z;

	Vector3 vecYZ;
	vecYZ.x = vecXY.x;
	vecYZ.y = vecXY.y * cosf(TO_RADIAN(-rot.x)) + vecXY.z * sinf(TO_RADIAN(-rot.x));
	vecYZ.z = vecXY.z * cosf(TO_RADIAN(-rot.x)) - vecXY.y * sinf(TO_RADIAN(-rot.x));

	vecYZ.SetLength(L);
	Vector3 pos_look = pos + vecYZ;
	m_look.set(pos_look);
	m_look.y += 5.f;

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
	SetCameraPositionAndTarget_UpVecY(VGet(m_pos.x, m_pos.y, m_pos.z), VGet(m_look.x, m_look.y, m_look.z));
}
//---------------------------------------------------------------------------------
//	èIóπèàóù
//---------------------------------------------------------------------------------
void Camera::Exit()
{
}

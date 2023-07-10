#include "Main.h"
#include "Game.h"
#include "Camera.h"

//---------------------------------------------------------------------------------
//	����������
//---------------------------------------------------------------------------------
void Camera::Init()
{
    //	�J�������W�ƌ�����W�̏����ݒ�
    m_pos.set( 0.0f, 20.0f, -30.0f );
    // m_look.set( 0.0f, 0.0f, 0.0f );
    m_rot.set( 30.f, 0.f, 0.f );
}
//---------------------------------------------------------------------------------
//	�X�V����
//---------------------------------------------------------------------------------
void Camera::Update()
{
    const float MOVE_SPEED = 0.1f;
    if( CheckMouseInput( MOUSE_INPUT_LEFT ) )
    {
        Vector2F move = { (float)GetMouseMoveX(), (float)GetMouseMoveY() };
        move *= MOVE_SPEED;
        m_rot.y += -move.x;
        m_rot.x += -move.y;
    }
}
//---------------------------------------------------------------------------------
//	�`�揈��
//---------------------------------------------------------------------------------
void Camera::Render()
{
    //	�J�������W�Ƃ݂���W��n���ăJ�����ݒ�
    // SetCameraPositionAndTarget_UpVecY( VGet( m_pos.x, m_pos.y, m_pos.z ), VGet( m_look.x, m_look.y, m_look.z ) );
    SetCameraPositionAndAngle( VGet( m_pos.x, m_pos.y, m_pos.z ),
                               TO_RADIAN( m_rot.x ),
                               TO_RADIAN( m_rot.y ),
                               TO_RADIAN( m_rot.z ) );
}
//---------------------------------------------------------------------------------
//	�I������
//---------------------------------------------------------------------------------
void Camera::Exit()
{
}

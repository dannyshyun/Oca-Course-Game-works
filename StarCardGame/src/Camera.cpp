#include "Main.h"
#include "Game.h"
#include "Camera.h"

//---------------------------------------------------------------------------------
//	初期化処理
//---------------------------------------------------------------------------------
void Camera::Init()
{
    //	カメラ座標と見る座標の初期設定
    m_pos.set( 0.0f, 20.0f, -30.0f );
    // m_look.set( 0.0f, 0.0f, 0.0f );
    m_rot.set( 30.f, 0.f, 0.f );
}
//---------------------------------------------------------------------------------
//	更新処理
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
//	描画処理
//---------------------------------------------------------------------------------
void Camera::Render()
{
    //	カメラ座標とみる座標を渡してカメラ設定
    // SetCameraPositionAndTarget_UpVecY( VGet( m_pos.x, m_pos.y, m_pos.z ), VGet( m_look.x, m_look.y, m_look.z ) );
    SetCameraPositionAndAngle( VGet( m_pos.x, m_pos.y, m_pos.z ),
                               TO_RADIAN( m_rot.x ),
                               TO_RADIAN( m_rot.y ),
                               TO_RADIAN( m_rot.z ) );
}
//---------------------------------------------------------------------------------
//	終了処理
//---------------------------------------------------------------------------------
void Camera::Exit()
{
}

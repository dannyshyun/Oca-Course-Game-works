#include "CameraBase.h"
#include <System/Component/ComponentCollisionSphere.h>
#include <System/Component/ComponentSpringArm.h>

BP_OBJECT_IMPL( CameraBase, "Camera" );

CameraBasePtr CameraBase::Create( float3 pos, float3 target )
{
    auto obj    = Scene::CreateObjectDelayInitialize<CameraBase>();
    obj->pos    = pos;
    obj->target = target;
    return obj;
}

bool CameraBase::Init()
{
    if( ! __super::Init() )
        return false;

    auto cam = AddComponent<ComponentCamera>();
    cam->SetPositionAndTarget( pos, target );
    cam->SetPerspective( 60.0f * DegToRad );

    return true;
}

#ifdef USE_MOUSE_CAMERA
void CameraBase::Update()
{
    auto spring_arm = GetComponent<ComponentSpringArm>();

            // SprintArmの回転にマウスの移動量を足しこむ
            rot += { GetMouseMoveY(), GetMouseMoveX(), 0 };

            // 足しこんだ回転を利用する
            spring_arm->SetSpringArmRotate( rot );
}
#endif

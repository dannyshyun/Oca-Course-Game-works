#include <System/Scene.h>
#include "GameMain.h"
#include "GameScene.h"
#include "Cards/CardTest.h"
#include "Cards/TableTest.h"
#include "Cameras/CameraBase.h"

#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCamera.h>
using namespace MainScene;

BP_CLASS_IMPL( TestScene, u8"Test" );

bool TestScene::Init()
{
    // table
    {
        auto table = TableTest::Create()->SetName( "Table" );
        table->SetScaleAxisXYZ( f32( 0.1f ) );
    }

    // card
    {
        auto card = CardTest::Create( CardParam( "Sword", 2 ),
                                      float3( 0.f, 1.3f, 0.f ) )
                        ->SetName( "Card" );
    }
#if 1
    // camera
    {
        float3 pos( 0, 37.5f, 40.3f );
        float3 target( 0, 0.8f, -0.5f );
        auto   cam = CameraBase::Create( pos, target )->SetName( "PlayCamera" );
        cam->SetRotationAxisXYZ( float3( 0, 180, 0 ) );
    }
    // camera
    {
        auto   table = Scene::GetObjectPtr<Object>( "Table" );
        float3 pos( 0, 80, 0.1f );
        float3 target( table->GetTranslate() );
        auto   cam = CameraBase::Create( pos, target )->SetName( "TopCamera" );
        cam->SetRotationAxisXYZ( float3( 0, 180, 0 ) );
    }
#else
    // camera
    {
        auto obj = Scene::CreateObjectPtr<Object>();
        obj->SetName( "camera" );
        auto cam = obj->AddComponent<ComponentCamera>();
        cam->SetPositionAndTarget(
            float3( 50.f, 140.f, -100.f ),
            Scene::GetObjectPtr<Object>( u8"Table" )->GetTranslate() );
        cam->SetPerspective( 60.0f * DegToRad );
    }
#endif
    IMGctrl.Init();
    Turn = LOAD_TURN;
    npc->Init();
    player->Init();
    return true;
}

void TestScene::Update()
{
    if( IsKeyOn( KEY_INPUT_1 ) )
        Scene::SetCurrentCamera( "TopCamera" );

    if( IsKeyOn( KEY_INPUT_2 ) )
        Scene::SetCurrentCamera( "PlayCamera" );
    counter++;
    npc->Update();
    player->Update();
}

void TestScene::Draw()
{
    auto   table = Scene::GetObjectPtr<Object>( "Table" );
    auto   card  = Scene::GetObjectPtr<Object>( "Card" );
    float1 h     = card->GetTranslate().y - table->GetTranslate().y;
    DrawFormatStringF( 16, 16, WHITE, ( TC ) "%f", (float)( h ) );
    // npc->Render();
    // player->Render();
    // ui->Render();
}

void TestScene::Exit()
{
}

void TestScene::GUI()
{
    ImGui::InputInt( "Counter", &counter );
}

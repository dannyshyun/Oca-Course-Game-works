#include <System/Scene.h>
#include "GameMain.h"
#include "GameScene.h"
#include "Cards/CardTest.h"

#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCamera.h>
using namespace MainScene;

BP_CLASS_IMPL( TestScene, u8"Test" );

bool TestScene::Init()
{
    // ground
    {
        auto obj = Scene::CreateObjectPtr<Object>()->SetName( "ground" );
        obj->AddComponent<ComponentModel>(
            "data/Sample/SwordBout/Stage/Stage00.mv1" );
        obj->SetScaleAxisXYZ( f32(0.01f) );
    }
    // camera
    {
        auto obj = Scene::CreateObjectPtr<Object>();
        obj->SetName( "camera" );
        auto cam = obj->AddComponent<ComponentCamera>();
        cam->SetPositionAndTarget( float3( 0.f, 100.f, -15.f ),
                                   float3( 0.f, 5.f, 0.f ) );
        cam->SetPerspective( 60.0f * DegToRad );
    }
    IMGctrl.Init();
    Turn = LOAD_TURN;
    npc->Init();
    player->Init();
    auto card = CardTest::Create()->SetName( "Card" );
    card->SetScaleAxisXYZ( f32(0.01f) );
    return true;
}

void TestScene::Update()
{
    counter++;
    npc->Update();
    player->Update();
}

void TestScene::Draw()
{
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

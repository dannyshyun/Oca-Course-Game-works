#include <System/Scene.h>
#include "GameMain.h"
#include "GameScene.h"
using namespace MainScene;


BP_CLASS_IMPL( TestScene, u8"Test" );

bool TestScene::Init()
{
    IMGctrl.Init();
    Turn = LOAD_TURN;
    npc->Init();
    player->Init();
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
    npc->Render();
    player->Render();
    ui->Render();
}

void TestScene::Exit()
{
}

void TestScene::GUI()
{
    ImGui::InputInt( "Counter", &counter );
}

#include <System/Component/ComponentModel.h>
#include "WinMain.h"
#include "Game/GameMain.h"
#include "BaseClass/Base.h"
#include "CardTest.h"

BP_OBJECT_IMPL( CardTest, "CardTest" );
CardTestPtr CardTest::Create( float3 pos )
{
    auto card = Scene::CreateObjectPtr<CardTest>();
    card->SetName( "CardTest" );
    card->SetTranslate( pos );
    return card;
}

bool CardTest::Init()
{
    __super::Init();
    auto model = AddComponent<ComponentModel>(
        "data/Sample/Coin/GoldCoin.mv1" );
    return true;
}

void CardTest::Update()
{
}

void CardTest::Render( bool is_show )
{
}

void CardTest::GUI()
{
    __super::GUI();
    ImGui::Begin( GetName().data() );
    {
        ImGui::Separator();
    }
    ImGui::End();
}

void CardTest::Exit()
{
}

u32 CardTest::GetCardVal() const
{
    return this->value;
}

u32 CardTest::GetImage() const
{
    return this->image;
}

#include <System/Component/ComponentModel.h>
#include "WinMain.h"
#include "Game/GameMain.h"
#include "BaseClass/Base.h"
#include "TableTest.h"

BP_OBJECT_IMPL( TableTest, "TableTest" );
TableTestPtr TableTest::Create( float3 pos )
{
    auto card = Scene::CreateObjectPtr<TableTest>();
    card->SetName( "TableTest" );
    card->SetTranslate( pos );
    return card;
}

bool TableTest::Init()
{
    __super::Init();

    if( auto model = AddComponent<ComponentModel>() )
    {
        model->Load( "data/Models/CardTable.mv1" );
        // mat
        {
            Material mat{};
            mat.AO = makeSptr<Texture>(
                "data/Textures/CardsAndTables_Mixed_AO.png" );
            mat.albedo = makeSptr<Texture>(
                "data/Textures/CardsAndTables_Base_color.png" );
            mat.normal = makeSptr<Texture>(
                "data/Textures/CardsAndTables_Normal_OpenGL.png" );
            mat.roughness = makeSptr<Texture>(
                "data/Textures/CardsAndTables_Roughness.png" );
            mat.metalness = makeSptr<Texture>(
                "data/Textures/CardsAndTables_Metallic.png" );
            materials.push_back( mat );
        }
        model->SetProc(
            "ModelDraw",
            [model, this]() {
                if( auto model_card = model->GetModelClass() )
                {
                    auto& mat = materials[0];
                    model_card->overrideTexture( Model::TextureType::Diffuse,
                                                 mat.albedo );
                    model_card->overrideTexture( Model::TextureType::AO,
                                                 mat.AO );
                    model_card->overrideTexture( Model::TextureType::Albedo,
                                                 mat.albedo );
                    model_card->overrideTexture( Model::TextureType::Normal,
                                                 mat.normal );
                    model_card->overrideTexture( Model::TextureType::Roughness,
                                                 mat.roughness );
                    model_card->overrideTexture( Model::TextureType::Metalness,
                                                 mat.metalness );

                    model_card->renderByMesh( 0 );
                }
            },
            ProcTiming::Draw );
    }

    return true;
}

void TableTest::Update()
{
}

void TableTest::Render()
{
}

void TableTest::GUI()
{
    __super::GUI();
    ImGui::Begin( GetName().data() );
    {
        ImGui::Separator();
    }
    ImGui::End();
}

void TableTest::Exit()
{
}

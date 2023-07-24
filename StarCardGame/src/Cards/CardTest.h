#pragma once
#include <System/Scene.h>
#include <utility>

struct CardParam
{
public:
    CardParam() :
        value( 0 ){};
    CardParam( const std::string& suit, u32 value )
    {
        this->suit  = std::move( suit );
        this->value = value;
    };

public:
    std::string suit;
    u32 value{ 0 };
};

USING_PTR( CardTest );
class CardTest : public Object
{
public:
    BP_OBJECT_TYPE( CardTest, Object );
    static CardTestPtr Create( CardParam param,
                               float3    pos = { 0.f, 0.f, 0.f } );
    virtual bool       Init() override;
    virtual void       Update() override;
    virtual void       Render( bool is_show );
    virtual void       GUI() override;
    virtual void       Exit() override;
    [[nodiscard]] virtual CardParam  GetCardParam() const;
    [[nodiscard]] virtual u32        GetImage() const;

    bool is_player = true;
    bool is_select = false;
    bool is_touch  = false;

protected:
    // 2D image data
    int    image = -1;
    float2 image_size{ 0.f, 0.f };
    // materials
    struct Material
    {
        std::shared_ptr<Texture> AO;
        std::shared_ptr<Texture> albedo;
        std::shared_ptr<Texture> normal;
        std::shared_ptr<Texture> roughness;
        std::shared_ptr<Texture> metalness;
    };
    std::vector<Material> materials;

    // card suit and value
    CardParam param{};
};

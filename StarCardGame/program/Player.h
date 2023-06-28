#pragma once
#include "Deck.h"
#include "Hand.h"
//---------------------------------------------------------------------------------
//	プレイヤークラス
//---------------------------------------------------------------------------------
class Player : public Base
{
public:
    Player( int image );
    void Init() override;          //	初期化処理
    void Update( uint16_t turn );  //	更新処理
    void Render() override;        //	描画処理
    void Release() override;       //	終了処理

    void SelectCard( CardBase card );

private:
    std::unique_ptr<Deck> deck;
    std::unique_ptr<Hand> hand;
};

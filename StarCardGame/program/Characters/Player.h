#pragma once
#include "Deck.h"
#include "Hand.h"
//---------------------------------------------------------------------------------
//	�v���C���[�N���X
//---------------------------------------------------------------------------------
class Player : public Base
{
public:
    Player( int image );
    void Init() override;     //	����������
    void Update() override;   //	�X�V����
    void Render() override;   //	�`�揈��
    void Release() override;  //	�I������

    void SelectCard( std::shared_ptr<CardBase> card );
    void CheckTouch( std::shared_ptr<CardBase> card );

    void ClickOk();

private:
    std::unique_ptr<Deck> deck;
    std::unique_ptr<Hand> hand;
};

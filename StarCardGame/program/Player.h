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
    void Init() override;          //	����������
    void Update( uint16_t turn );  //	�X�V����
    void Render() override;        //	�`�揈��
    void Release() override;       //	�I������

    void SelectCard( CardBase card );

private:
    std::unique_ptr<Deck> deck;
    std::unique_ptr<Hand> hand;
};

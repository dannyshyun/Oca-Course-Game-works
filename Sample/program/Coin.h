#pragma once
#include "Base.h"

class Coin : public Base
{
public:
	Coin(int model);
	~Coin();

	void Init(int model); //	����������
	void Update();		  //	�X�V����
	void Render();		  //	�`�揈��
	void Exit();		  //	�I������

private:
};

#pragma once
#include "Base.h"

class Coin : public Base
{
public:

	Coin(int model, Vector3 pos);
	~Coin();

	void Init(int model, Vector3 pos);		//	����������
	void Update();		//	�X�V����
	void Render();		//	�`�揈��
	void Exit();		//	�I������

private:

};

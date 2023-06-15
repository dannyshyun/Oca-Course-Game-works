#pragma once
#include "CardBase.h"
#include <vector>
#include <memory>
typedef std::vector<std::shared_ptr<CardBase>> cards;
typedef std::unique_ptr<cards>				   ptr_cards;
class Deck : public Base
{
public:
	Deck();
	~Deck();
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	cards Deal( int num );
	void				   Revoke( int num );

private:
	ptr_cards deck;
};
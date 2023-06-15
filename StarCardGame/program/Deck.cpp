#include "Base.h"
#include "Deck.h"
Deck::Deck()
{
	this->deck = std::make_unique<cards>();
}

Deck::~Deck()
{
}
void Deck::Init()
{
}

void Deck::Update()
{
}

void Deck::Render()
{
}

void Deck::Release()
{
}

cards Deck::Deal( int num )
{
	return 
        this->deck->empty() ? 
        cards() : 
        this->deck->size() < num ? 
        *deck : 
        cards( deck->begin(), deck->begin() + ( num, -1 ) );

	
	if(this->deck->empty()){
		return cards();
	}
    else if(this->deck->size() < num){
        // todo
        cards temp(deck->begin( ), deck->end());
		cards().swap(*deck);
		return *deck;
	}
    else{

    }
}

void Deck::Revoke( int num )
{

}

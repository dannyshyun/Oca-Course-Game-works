#include "Main.h"
#include "Game.h"
#include "Base.h"
#include "CardBase.h"
#include "ActionCard.h"
#include "ItemCard.h"
#include "ChanceCard.h"
#include "CurseCard.h"
#include "HpPlusCard.h"
#include "Deck.h"
#include "json.h"
#include <fstream>
#include <utility>
#define NewActionCard             \
    std::make_shared<ActionCard>( \
        IMGctrl.GetCardIMGdata( suit, value ), value, 0, suit )
#define NewChanceCard             \
    std::make_shared<ChanceCard>( \
        IMGctrl.GetCardIMGdata( suit, value ), value, 0 )
#define NewCurseCard             \
    std::make_shared<CurseCard>( \
        IMGctrl.GetCardIMGdata( suit, value ), value, 0 )
#define NewHpPlusCard             \
    std::make_shared<HpPlusCard>( \
        IMGctrl.GetCardIMGdata( suit, value ), value, 0 )
using json = nlohmann::json;
Deck::Deck( int image ) : Base( image )
{
    deck = std::make_unique<Cards>();
}

Deck::~Deck()
{
}
void Deck::Init()
{
    this->image    = IMGctrl.GetUIIMGdata( "deck" );
    this->card_num = 0;
    LoadCardsIMG();
    Shuffle();
}

void Deck::Update()
{
}

void Deck::Render()
{
    DrawRotaGraph( 60, 40, 1, 0, image, true );
    DrawFormatString( 85, 30, WHITE, (const TCHAR*)"%2d", card_num );
}

void Deck::Release()
{
}

Cards Deck::Deal( uint16_t num )
{
    if ( deck->empty() )
    {
        return Cards();
    }
    else if ( deck->size() < num )
    {
        // todo
        Cards temp( deck->begin(), deck->end() );
        Cards().swap( *deck );
        return temp;
    }
    else
    {
        Cards temp( deck->begin(), deck->begin() + num );
        deck->erase( deck->begin(), deck->begin() + num );
        return temp;
    }
}

uint16_t Deck::GetCardNum() const
{
    return card_num;
}

void Deck::Revoke( Cards cards )
{
    for ( auto& card: cards ) { deck->push_back( card ); }
}

bool Deck::LOAD()
{
    if ( card_num < deck->size() )
    {
        card_num++;
        return false;
    }
    return true;
}

bool Deck::Shuffle()
{
    for ( auto& card: *deck )
    {
        uint16_t rand = GetRand( deck->size() - 1 );
        std::swap( card, *( deck->begin() + rand ) );
    }
    return true;
}

void Deck::LoadCardsIMG()
{
    // load json file
    std::ifstream file( "data/deckData.json" );
    json          jfile = json::parse( file );
    // parse json object
    for ( auto& obj: jfile )
    {
        std::string suit  = obj["suit"];
        uint16_t    value = obj["value"];
        uint16_t    num   = obj["num"];
        // insert the card * num times
        for ( uint16_t i = 0; i < num; i++ )
        {
            // check the suit to new classes
            ( suit == "sword" || suit == "gun" || suit == "shield" ||
              suit == "move" || suit == "star" )
                ? deck->push_back( NewActionCard )
            : suit == "chance" ? deck->push_back( NewChanceCard )
            : suit == "curse"  ? deck->push_back( NewCurseCard )
            : suit == "hpPlus" ? deck->push_back( NewHpPlusCard )
                               : deck->push_back( nullptr );
        }
    }
}

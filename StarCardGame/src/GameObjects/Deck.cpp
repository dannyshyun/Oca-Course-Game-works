#include "WinMain.h"
#include "Game/GameMain.h"
#include "BaseClass/Base.h"
#include "Cards/Action/ActionCard.h"
#include "Cards/Item/ItemCard.h"
#include "Cards/Item/ChanceCard.h"
#include "Cards/Item/CurseCard.h"
#include "Cards/Item/HpPlusCard.h"
#include "Deck.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <utility>

using json = nlohmann::json;

Deck::Deck( int image ) : Base( image )
{
    // new pointer
    deck = std::make_unique<Cards>();
}

Deck::~Deck()
{
}

void Deck::Init()
{
    // get IMG data from UI container
    this->image    = IMGctrl.GetUIIMGdata( "deck" );
    this->card_num = 0;
    LoadCardsIMG();
    Shuffle();
}

void Deck::Update()
{
    if( Turn != LOAD_TURN )
        // show card num in deck immediately
        card_num = deck->size();
}

void Deck::Render( bool is_player )
{
    uint16_t y = is_player            //!< the position of deck
                     ? WINDOW_H - 40  //!< player
                     : 40;            //!< npc
    // render image
    DrawRotaGraph( 60, y, 1, 0, image, true );
    // render num
    DrawFormatString( 85, y - 10, WHITE, ( TC ) "%2d", card_num );
}

void Deck::Release()
{
}

uint16_t Deck::GetCardNum() const
{
    return card_num;
}

void Deck::Revoke( Cards cards )
{
    for( auto& card: cards )
    {
        // insert to the deck
        deck->push_back( card );
    }
}

bool Deck::Load()
{
    // return true when loading is done
    if( card_num < deck->size() )
    {
        card_num++;
        return false;
    }
    return true;
}

bool Deck::Shuffle()
{
    // return true when shuffling is done
    for( auto& card: *deck )
    {
        // index of container to swap
        uint16_t rand = GetRand( deck->size() - 1 );
        std::swap( card, *( deck->begin() + rand ) );
    }
    return true;
}

Cards Deck::Deal( uint16_t num )
{
    // no card could be returned
    if( deck->empty() )
    {
        return Cards();
    }
    // less than num cards could be returned
    else if( deck->size() < num )
    {
        Cards temp( deck->begin(), deck->end() );
        Cards().swap( *deck );
        return temp;
    }
    // return num cards
    else
    {
        Cards temp( deck->begin(), deck->begin() + num );
        deck->erase( deck->begin(), deck->begin() + num );
        return temp;
    }
}
Card<CardBase> Deck::NewActionCard( std::string suit, u32 value )
{
    return std::make_shared<ActionCard>( IMGctrl.GetCardIMGdata( suit, value ),
                                         value,
                                         0,
                                         suit );
}

Card<CardBase> Deck::NewChanceCard( std::string suit, u32 value )
{
    return std::make_shared<ChanceCard>( IMGctrl.GetCardIMGdata( suit, value ),
                                         value,
                                         0 );
}

Card<CardBase> Deck::NewHpPlusCard( std::string suit, u32 value )
{
    return std::make_shared<HpPlusCard>( IMGctrl.GetCardIMGdata( suit, value ),
                                         value,
                                         0 );
}

Card<CardBase> Deck::NewCurseCard( std::string suit, u32 value )
{
    return std::make_shared<CurseCard>( IMGctrl.GetCardIMGdata( suit, value ),
                                        value,
                                        0 );
}

void Deck::LoadCardsIMG()
{
    // load json file
    std::ifstream file( "data/deckData.json" );
    json          jfile = json::parse( file );
    // parse json object
    for( auto& obj: jfile )
    {
        std::string suit  = obj["suit"];
        uint16_t    value = obj["value"];
        uint16_t    num   = obj["num"];
        // insert the card * num times
        for( uint16_t i = 0; i < num; i++ )
        {
            // check suit and new class
            ( suit == "sword" || suit == "gun" || suit == "shield" ||
              suit == "move" || suit == "star" )
                ? deck->push_back( NewActionCard( suit, value ) )
            : suit == "chance" ? deck->push_back( NewChanceCard( suit, value ) )
            : suit == "curse"  ? deck->push_back( NewCurseCard( suit, value ) )
            : suit == "hpPlus" ? deck->push_back( NewHpPlusCard( suit, value ) )
                               : deck->push_back( nullptr );
        }
    }
}

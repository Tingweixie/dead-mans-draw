#include "Deck.h"
#include "CannonCard.h"
#include "ChestCard.h"
#include "HookCard.h"
#include "KeyCard.h"
#include "KrakenCard.h"
#include "MapCard.h"
#include "MermaidCard.h"
#include "OracleCard.h"
#include "SwordCard.h"
#include <cstdlib>

Deck::Deck()
{

}

Deck::~Deck()
{
    while (!cards.empty())
    {
        delete cards.back();
        cards.pop_back();
    }
}

void Deck::createStandardDeck()
{
    for (int i = 2; i <= 7; i++)
    {
        cards.push_back(new CannonCard(i));
        cards.push_back(new ChestCard(i));
        cards.push_back(new KeyCard(i));
        cards.push_back(new SwordCard(i));
        cards.push_back(new HookCard(i));
        cards.push_back(new OracleCard(i));
        cards.push_back(new MapCard(i));
        cards.push_back(new KrakenCard(i));
  }
    for (int i = 4; i <= 9; i++)
    {
    cards.push_back(new MermaidCard(i));
    }
    }


void  Deck::shuffle()
{
    for (int i = 0; i < cards.size(); i++)
    {
        int randomIndex = rand() % cards.size();

        Card* temp = cards[i];
        cards[i] = cards[randomIndex];
        cards[randomIndex] = temp;
    }
}

Card* Deck::drawTop()
{
    if (cards.empty())

    {
        return nullptr;
    }

    Card* topCard = cards.back();
    cards. pop_back();
    return topCard;
}

Card* Deck::peekTop() const
{
    if (cards.empty())
    {
        return nullptr;
    }
    return cards.back();
}

bool Deck::isEmpty() const
{
    return cards.empty();
}

int Deck::size() const
{
    return cards.size();
}
/******************************************************************************
*
* Amer Yono
* CS 281 - 0798, Fall 2020
* Final Project
*
*******************************************************************************
*/

// include external libraries
#include <string>
#include <vector>

// include internal libraries
#include "Room.h"
#include "Player.h"
#include "Treasure.h"

int Player::m_pCount = 0;

Player::Player(const std::string& name, int nLives)
{
    m_id = PLAYER_CONTAINER;
    m_name = name;
    m_nLives = nLives;
}

int Player::getLives() const { return m_nLives; }

int Player::setLives(int n) { return m_nLives = n; }

int Player::addLives(int n) { return m_nLives += n; }

int Player::loseLife() { return --m_nLives; }

int Player::addRoomVisit(Room* pR)
{
    m_pRoomsVisitedV.push_back(pR);
    return m_pRoomsVisitedV.size();
}

void Player::clearRoomVisits()
{
    m_pRoomsVisitedV.clear();
}

int Player::getRoomVisits(std::vector<Room*>& pRV)
{
    pRV.clear();
    for (Room* pR : m_pRoomsVisitedV)
    {
        pRV.push_back(pR);
    }
    return m_pRoomsVisitedV.size(); 
}

int Player::addTreasure(Treasure* pT)
{
    int n = Container::addTreasure(pT);

    m_points += pT->getPoints();

    return n;
}

Treasure* Player::removeTreasure()
{
    Treasure* pT = Container::removeTreasure();

    if (pT != nullptr)
        m_points -= pT->getPoints();

    return pT;
}

int Player::addWeapon(Weapon* pW)
{
    int n = Container::addWeapon(pW);

    m_points += pW->getPoints();

    return n;
}

Weapon* Player::removeWeapon()
{
    Weapon* pW = Container::removeWeapon();

    if (pW != nullptr)
        m_points -= pW->getPoints();

    return pW;
}

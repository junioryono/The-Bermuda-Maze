/******************************************************************************
*
* Amer Yono
* CS 281 - 0798, Fall 2020
* Final Project
*
*******************************************************************************
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "Treasure.h"
#include "Weapon.h"
#include "Container.h"

constexpr int PLAYER_LIVES = 3;

class Player : public Container
{
private:
    static int m_pCount;

    int m_nLives;
    std::vector<Room*> m_pRoomsVisitedV;

public:
    Player(const std::string& name, int nLives);

    int getLives() const;
    int setLives(int n);
    int addLives(int n);
    int loseLife();

    int addRoomVisit(Room* pR);
    void clearRoomVisits();
    int getRoomVisits(std::vector<Room*>& pRV);

    int addTreasure(Treasure* pT);
    Treasure* removeTreasure();

    int addWeapon(Weapon* pW);
    Weapon* removeWeapon();
};

#endif
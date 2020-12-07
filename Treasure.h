/******************************************************************************
*
* Amer Yono
* CS 281 - 0798, Fall 2020
* Final Project
*
*******************************************************************************
*/

#ifndef TREASURE_H
#define TREASURE_H

#include <string>

#include "CarryIt.h"

int constexpr TREASURE_POINTS = 100;

class Treasure : public CarryIt
{
private:
    static int m_tCount;

public:
    Treasure();
    Treasure(const std::string& tName, int points);

    static int getTreasureCount();
};

#endif

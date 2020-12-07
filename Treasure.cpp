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

// include internal libraries
#include "CarryIt.h"
#include "Treasure.h"

int Treasure::m_tCount = 0;

Treasure::Treasure(const std::string& tName, int points)
{
    m_tCount++;

    m_id = TREASURE_CARRYIT;
    m_name = tName;
    m_points = points;
}

Treasure::Treasure() : Treasure("Treasure", TREASURE_POINTS) { }

int Treasure::getTreasureCount() { return m_tCount; }




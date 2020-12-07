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
#include <cstdlib>

#include "CarryIt.h"

constexpr int MAX_POWER = 5;
constexpr int MIN_POWER = 3;

CarryIt::CarryIt()
{
    m_id = GENERIC_CARRYIT;
    m_name = "carry me";

    m_power = rand() % MAX_POWER + MIN_POWER;
    m_roomInfo = 0;
    m_playerInfo = 0;
}

void CarryIt::setPower(int power)
{
    m_power = power;
}

int CarryIt::getPower() const
{
    return m_power;
}

int CarryIt::addPower(int morePower)
{
    return m_power += morePower;
}

std::ostream& operator<< (std::ostream& m_ostream, const CarryIt& object)
{
    std::string str;
    m_ostream << object.getName(str);
    m_ostream << " (" << object.getPoints() << " points)\n";

    return m_ostream;
}


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
#include "Weapon.h"

int Weapon::m_wCount = 0;

Weapon::Weapon(const std::string& wName, int points)
{
    m_wCount++;

    m_id = WEAPON_CARRYIT;
    m_name = wName;
    m_points = points;
}

Weapon::Weapon() : Weapon("Weapon", WEAPON_POINTS) { }

int Weapon::getWeaponCount() { return m_wCount; }

int Weapon::setUsesRemaining(int uses)
{
    return m_usesRemaining = uses;
}

int Weapon::getUsesRemaining() const
{
    return m_usesRemaining;
}

int Weapon::addUsesRemaining(int uses)
{
    return m_usesRemaining += uses;
}

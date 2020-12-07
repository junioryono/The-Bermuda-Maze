/******************************************************************************
*
* Amer Yono
* CS 281 - 0798, Fall 2020
* Final Project
*
*******************************************************************************
*/

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

#include "CarryIt.h"

int constexpr WEAPON_POINTS = 100;
int constexpr WEAPON_USES = 1;

class Weapon : public CarryIt
{
private:
    int m_usesRemaining;

    static int m_wCount;

public:
    Weapon();
    Weapon(const std::string& wName, int points);

    static int getWeaponCount();

    int setUsesRemaining(int uses);
    int getUsesRemaining() const;
    int addUsesRemaining(int uses);
};

#endif

/******************************************************************************
*
* Amer Yono
* CS 281 - 0798, Fall 2020
* Final Project
*
*******************************************************************************
*/

#ifndef CARRYIT_H
#define CARRYIT_H

#include <iostream>

#include "Element.h"

int constexpr TREASURE_CARRYIT  = 't';
int constexpr WEAPON_CARRYIT    = 'w';
int constexpr MAGICWORD_CARRYIT = 'm';
int constexpr BOGEY_CARRYIT     = 'b';
int constexpr GENERIC_CARRYIT   = 'c';

class CarryIt : public Element
{
protected:
    int m_power;
    int m_roomInfo;
    int m_playerInfo;

public:
    CarryIt();
    void setPower(int power);
    int getPower() const;
    int addPower(int morePower);

    friend std::ostream& operator<< (std::ostream& os, const CarryIt &item);
};

#endif
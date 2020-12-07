/******************************************************************************
*
* Amer Yono
* CS 281 - 0798, Fall 2020
* Final Project
*
*******************************************************************************
*/

#ifndef BOGEY_H
#define BOGEY_H

#include <string>

#include "Element.h"
#include "CarryIt.h"

int constexpr m_bogeyPoints = 100;

class Bogey : public CarryIt
{
private:
    static int m_bogeyCount;

public:
    Bogey();
    Bogey(std::string name, int points);
    static int getBogeyCount();
};

#endif
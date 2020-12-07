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
#include "Bogey.h"

int Bogey::m_bogeyCount = 0;

//***********************************************************
// Bogey()
//
// overload constructor
//***********************************************************
Bogey::Bogey(std::string name, int points)
{ 
    m_bogeyCount++;

    m_id = BOGEY_CARRYIT;
    m_name = name;
    m_points = points;
}

//***********************************************************
// Bogey()
//
// constructor
//***********************************************************
Bogey::Bogey() : Bogey("bogey", m_bogeyPoints) { }

int Bogey::getBogeyCount() { return m_bogeyCount; }

/******************************************************************************
*
* Amer Yono
* CS 281 - 0798, Fall 2020
* Final Project
*
*******************************************************************************
*/

// include internal libraries
#include "app.h"

void initRoomMap()
{
    // Can only move North
    g_pPrisonCell->setDirectionPtr(ROOM_UP, g_pInfirmary);

    // Center of map, can move anywhere
    g_pInfirmary->setDirectionPtr(ROOM_UP, g_pYard);
    g_pInfirmary->setDirectionPtr(ROOM_RIGHT, g_pKitchen);
    g_pInfirmary->setDirectionPtr(ROOM_DOWN, g_pPrisonCell);
    g_pInfirmary->setDirectionPtr(ROOM_LEFT, g_pShowers);

    // Can only move West
    g_pKitchen->setDirectionPtr(ROOM_LEFT, g_pInfirmary);

    // Can only move East
    g_pShowers->setDirectionPtr(ROOM_RIGHT, g_pInfirmary);

    // Can only move South
    g_pYard->setDirectionPtr(ROOM_DOWN, g_pInfirmary);
}

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
#include <vector>

// include internal libraries
#include "Room.h"
#include "Treasure.h"
#include "Weapon.h"

int Room::m_rCount = 0;

Room::Room(const std::string& name, int points)
{
    m_rCount++;

    m_id = ROOM_CONTAINER;
    m_name = name;
    m_points = points;
    m_entryText = "entering " + m_name;
    m_exitText = "exiting " + m_name;

    m_roomTextArray[ROOM_UP] = "You cannot go up";
    m_roomTextArray[ROOM_DOWN] = "You cannot go down";
    m_roomTextArray[ROOM_RIGHT] = "You cannot go right";
    m_roomTextArray[ROOM_LEFT] = "You cannot go left\n";

    m_nextRoomPtrArray[ROOM_UP] = nullptr;
    m_nextRoomPtrArray[ROOM_DOWN] = nullptr;
    m_nextRoomPtrArray[ROOM_RIGHT]  = nullptr;
    m_nextRoomPtrArray[ROOM_LEFT]  = nullptr;

}

Room::Room() : Room("room", ROOM_POINTS)  { }

int Room::getRoomCount() const { return m_rCount; }

void Room::setDirectionText(int direction, const std::string& str)
{ m_roomTextArray[direction] = str; }

std::string& Room::getDirectionText(int direction, std::string& str) const
{ return str = m_roomTextArray[direction]; }

void Room::setDirectionPtr(int direction, Room* pRoom)
{ m_nextRoomPtrArray[direction] = pRoom; }

Room* Room::getDirectionPtr(int direction) const 
{ return m_nextRoomPtrArray[direction]; }


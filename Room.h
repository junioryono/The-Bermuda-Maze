/******************************************************************************
*
* Amer Yono
* CS 281 - 0798, Fall 2020
* Final Project
*
*******************************************************************************
*/

#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <array>
#include <vector>

#include "Container.h"
#include "Treasure.h"
#include "Weapon.h"

int constexpr ROOM_NDIR = 16;
int constexpr ROOM_POINTS = 150;

int constexpr ROOM_UP = 0;
int constexpr ROOM_DOWN = 1;
int constexpr ROOM_RIGHT = 2;
int constexpr ROOM_LEFT = 3;

int constexpr ROOM_DEAD_END = -2;
int constexpr ROOM_ERROR = -3;

class Room : public Container
{
private:

    static int m_rCount;

    std::array <std::string, ROOM_NDIR> m_roomTextArray;

    std::array<Room*, ROOM_NDIR> m_nextRoomPtrArray;

    std::string m_entryText;
    std::string m_exitText;

public:
    Room();
    Room(const std::string& name, int points);

    int getRoomCount() const;
    
    void setDirectionText(int direction, const std::string& str);
    std::string& getDirectionText(int direction, std::string& str) const;

    void setDirectionPtr(int direction, Room* pRoom);
    Room* getDirectionPtr(int direction) const;
};

#endif
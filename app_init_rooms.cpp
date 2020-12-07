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

Room* initPrisonCell()
{
    Room* pRoom = new Room("Prison Cell", 30);
    pRoom->setDirectionText(ROOM_UP, "The Infirmary is upward");
    pRoom->setDirectionText(ROOM_DOWN, "You cannot go down");
    pRoom->setDirectionText(ROOM_RIGHT, "You cannot go right");
    pRoom->setDirectionText(ROOM_LEFT, "You cannot go left");

    Bogey* pBogey = new Bogey("John, The Cell Watcher", 210);
    pBogey->setText("The prison guard yells, 'What do you think you're doing!?'");
    pRoom->addBogey(pBogey);

    Treasure* pTreasure = new Treasure("Cell Gold", 100);
    pRoom->addTreasure(pTreasure);

    return pRoom;
}

Room* initInfirmary()
{
    Room* pRoom = new Room("Infirmary", 30);
    pRoom->setDirectionText(ROOM_UP, "The Yard is upward");
    pRoom->setDirectionText(ROOM_DOWN, "The Prison Cell is downward");
    pRoom->setDirectionText(ROOM_RIGHT, "The Kitchen is to the right");
    pRoom->setDirectionText(ROOM_LEFT, "The Showers are to the left");

    return pRoom;
}

Room* initKitchen()
{
    Room* pRoom = new Room("Kitchen", 30);
    pRoom->setDirectionText(ROOM_LEFT, "The Infirmary is to the left");

    MagicWord* pMagicWord = new MagicWord("Noodles", 210);
    pRoom->addMagicWord(pMagicWord);

    return pRoom;
}

Room* initShowers()
{
    Room* pRoom = new Room("Showers", 30);
    pRoom->setDirectionText(ROOM_RIGHT, "The Infirmary is to the right");

    Weapon* pWeapon = new Weapon("Toothbrush", 210);
    pRoom->addWeapon(pWeapon);

    return pRoom;
}

Room* initYard()
{
    Room* pRoom = new Room("Yard", 30);
    pRoom->setDirectionText(ROOM_DOWN, "The Infirmary is downward");

    Bogey* pBogey = new Bogey("Matthew, The Hellicopter Watcher", 210);
    pBogey->setText("The prison guard yells, 'What do you think you're doing!?'");
    pRoom->addBogey(pBogey);

    Treasure* pTreasure = new Treasure("Cell Gold", 100);
    pRoom->addTreasure(pTreasure);

    return pRoom;
}

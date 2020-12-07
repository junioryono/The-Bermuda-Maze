/******************************************************************************
*
* Amer Yono
* CS 281 - 0798, Fall 2020
* Final Project
*
*******************************************************************************
*/

// include external libraries
#include <sstream>
#include <vector>

// include internal libraries
#include "app.h"

int getInventory(Container* pC, std::vector<std::string>& msgQ)
{
    int total = 0;
    std::string str;
    char cType = pC->getId();

    std::vector<Bogey*> pBogeyV;
    int nBogey = pC->getBogeyInfo(pBogeyV);
    total += nBogey;

    if (nBogey > 0)
    {
        std::stringstream ss;

        ss << "\n";

        if (cType == ROOM_CONTAINER)
            ss << "There is a prison guard here!\n";
        else if (nBogey > 1)
            ss << "You've defeated " << nBogey << " the prison guards!\n";
        else
            ss << "You've defeated the prison guard!\n";

        for (Bogey* pB : pBogeyV)
        {
            ss << *pB;
        }

        msgQ.push_back(ss.str());
    }

    std::vector<Weapon*> pWeaponV;
    int nWeapon = pC->getWeaponInfo(pWeaponV);
    total += nWeapon;

    if (nWeapon > 0)
    {
        std::stringstream ss;

        if (cType == ROOM_CONTAINER)
            ss << "There is a weapon in the room! Pick it up!\n";
        else
            ss << "You have a weapon!\n";

        for (Weapon* pW : pWeaponV)
        {
            ss << *pW;
        }

        msgQ.push_back(ss.str());
    }

    std::vector<MagicWord*> pMagicWordV;
    int nMagicWord = pC->getMagicWordInfo(pMagicWordV);
    total += nMagicWord;

    if (nMagicWord > 0)
    {
        std::stringstream ss;

        if (cType == ROOM_CONTAINER)
            ss << "There is a magic word in the room! Pick it up!\n";
        else
            ss << "You have a magic word!\n";

        msgQ.push_back(ss.str());
    }

    std::vector<Treasure*>pTreasureV;
    int nTreasure = pC->getTreasureInfo(pTreasureV);
    total += nTreasure;

    if (nTreasure > 0)
    {
        std::stringstream ss;

        if (cType == ROOM_CONTAINER)
            ss << "There is treasure here!\n";
        else
            ss << "You have treasure!\n";

        for (Treasure* pT : pTreasureV)
            ss << *pT;

        msgQ.push_back(ss.str());
    }

    return total;
}

bool getInfo(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    std::stringstream ss;
    ss << "You have " << pP->getPoints() << " points.\n";
    ss << "You have " << pP->getLives() << " lives left.\n\n";

    getInventory(pR, msgQ);

    getInventory(pP, msgQ);

    std::vector<Room*> pRoomVisitsV;
    int nVisits = pP->getRoomVisits(pRoomVisitsV);

    ss << "You have visited " << nVisits;
    if (nVisits > 1) 
        ss << " rooms:\n";
    else
        ss << " room:\n";

    for (Room* pR : pRoomVisitsV)
    {
        std::string str;
        ss << pR->getName(str) << "\n";
    }

    ss << "\n";
    ss << "Total rooms: " << pR->getRoomCount() << "\n";
    ss << "Total treasures: " << Treasure::getTreasureCount() << "\n";
    ss << "Total weapons: " << Weapon::getWeaponCount() << "\n";
    ss << "Total magic words: " << MagicWord::getMagicWordCount() << "\n";
    ss << "Total guards: " << Bogey::getBogeyCount() << "\n";
    msgQ.push_back(ss.str());

    return true;
}

bool getAllInfo(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    std::string str;
    msgQ.push_back("You're in the " + pR->getName(str) + ".");

    getInfo(pP, pR, msgQ);

    return true;
}

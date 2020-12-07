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

bool interAct(Player* pP, Room* pR, std::vector<std::string>& msgQ);

bool grabTreasure(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    if (pR->getBogeyCount() > 0)
    {
        msgQ.push_back("A guard is protecting the treasure!");

        std::vector<Bogey*> bV;
        pR->getBogeyInfo(bV);
        Bogey* pB = bV.back();

        std::string str;
        pB->getText(str);
        msgQ.push_back("The guard yells at you saying, '" + str + "'\n");

        return false;
    }

    Treasure* pT = pR->removeTreasure();
    if (pT == nullptr)
    {
        msgQ.push_back("There's no treasure here.");
        return false;
    }

    pP->addTreasure(pT);

    std::string str;
    std::stringstream ss;
    ss << "You have a " << pT->getName(str) << " worth "
        << pT->getPoints() << " points\n";

    msgQ.push_back(ss.str());

    return true;
}

bool dropTreasure(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    Treasure* pT = pP->removeTreasure();

    if (pT == nullptr)
    {
        msgQ.push_back("You have no treasure to drop!");
        return false;
    }

    pR->addTreasure(pT);

    std::string str;
    msgQ.push_back("You dropped a " + pT->getName(str));

    return true;
}

bool grabWeapon(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    Weapon* pW = pR->removeWeapon();

    if (pW == nullptr)
    {
        msgQ.push_back("There's no weapon here.");
        return false;
    }

    pP->addWeapon(pW);

    std::string str;
    std::stringstream ss;
    ss << "You have a " << pW->getName(str) << " worth "
        << pW->getPoints() << " points\n";

    msgQ.push_back(ss.str());

    return true;
}

bool dropWeapon(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    Weapon* pW = pP->removeWeapon();

    if (pW == nullptr)
    {
        msgQ.push_back("You have no weapon to drop!");
        return false;
    }

    pR->addWeapon(pW);

    std::string str;
    msgQ.push_back("You dropped a " + pW->getName(str));

    return true;
}

bool grabMagicWord(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    MagicWord* pW = pR->removeMagicWord();

    if (pW == nullptr)
    {
        msgQ.push_back("There's no magic word here.\n");
        return false;
    }

    pP->addMagicWord(pW);

    std::string str;
    std::stringstream ss;
    ss << "You found a magic word named '" << pW->getName(str) << "' worth "
        << pW->getPoints() << " points\n";

    msgQ.push_back(ss.str());

    return true;
}

char attackGuard(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    if (!interAct(pP, pR, msgQ))
    {
        std::string str;
        msgQ.push_back(pP->getName(str) + ", you were unsuccessful in your attack.\n");

        int nLivesLeft = pP->loseLife();
        if (nLivesLeft <= 0)
        {
            msgQ.push_back("You ran out of lives.\n");

            return 'q';
        }
        
        std::stringstream ss;
        ss << "You have " << nLivesLeft << "  lives remaining.\n";
        msgQ.push_back(ss.str());
    }

    return 0;
}

bool interAct(Player * pP, Room * pR, std::vector<std::string> & msgQ)
{
    if (pR->getBogeyCount() == 0)
    {
        msgQ.push_back("No prison guards are here.");
        return true;
    }

    std::vector<Bogey*> bV;
    pR->getBogeyInfo(bV);
    Bogey* pB = bV.back();
    int bPower = pB->getPower();

    if (pP->getWeaponCount() == 0)
    {
        if (!hasMagicWord(pP))
        {
            return false;
        }
        else
        {
            msgQ.push_back("You have successfully bribed the prison guard with your magic word!");
            msgQ.push_back("Looks like he won't be defending anything in this room anymore! :)\n");

            pP->addPoints(pB->getPoints());
            pR->removeBogey();
            pP->addBogey(pB);

            return true;
        }
    }

    std::vector<Weapon*> wV;
    pP->getWeaponInfo(wV);
    Weapon* pW = wV.back();
    int wPower = pW->getPower();

    std::string wName, bName;
    msgQ.push_back("You attacked " + pB->getName(bName) +
                   " with your " + pW->getName(wName) + "!");

    std::string str;
    msgQ.push_back(pW->getText(str));

    msgQ.push_back(pB->getText(str));

    if (wPower >= bPower)
    {
        int bPoints = pB->getPoints();

        std::stringstream ss;
        ss << bPoints << " points for defeating " << bName << "!\n";
        ss << "Looks like he won't be defending anything in this room anymore! :)\n";
        msgQ.push_back(ss.str());

        pP->addPoints(bPoints);
        pR->removeBogey();
        pP->addBogey(pB);

        return true;
    }

    if (wPower > 0)
    {
        msgQ.push_back("\nYou missed the " + bName + "!\n");
        pB->setPower(bPower - wPower);
        return true;
    }

    return false;

}

bool lookAllDirections(Room* pR, std::vector<std::string>& msgQ)
{
    std::string str;
    msgQ.push_back("You're in the " + pR->getName(str) + "\n");

    for (int i = 0; i < ROOM_NDIR; i++)
    {
        if (pR->getDirectionText(i, str) != "")
            msgQ.push_back(str);
    }

    getInventory(pR, msgQ);

    return true;
}

Room* movePlayer(Player* pP, Room* pR, int direction, std::vector<std::string>& msgQ)
{
    std::string str = "There isn't a room in this direction. Type in (L) to look around you.\n";

    Room* pNextRoom = pR->getDirectionPtr(direction);
    if (pNextRoom != nullptr)
    {
        visitRoom(pP, pNextRoom, msgQ);

        getInventory(pNextRoom, msgQ);

        return pNextRoom;
    }
    else
    {
        msgQ.push_back(str);
    }

    return pR;
}

bool visitRoom(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    int points = pR->getPoints();
    pP->addPoints(points);

    pP->addRoomVisit(pR);

    std::string str, roomName;
    msgQ.push_back("You're in the " + pR->getName(roomName) + ".");

    if (pR->getPoints() > 0)
    {
        std::stringstream ss;
        ss << "You earned " << points << " points for entering " << roomName << "!\n";

        msgQ.push_back(ss.str());
        pR->setPoints(0);
    }

    return true;
}

bool hasMagicWord(Player * pP)
{
    std::vector<MagicWord*> wV;
    pP->getMagicWordInfo(wV);
    

    if (wV.empty())
    {
        return false;
    }
    else
    {
        MagicWord* pW = wV.back();
        std::string wName;


        std::string str;
        std::cout << "\nYou have no weapons on you! If you remember the magic word you found, type it here: ";
        std::cin >> str;
        if (str.compare(pW->getName(wName)) == 0)
            return true;
        else
            return false;
    }   
}

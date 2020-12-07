/******************************************************************************
*
* Amer Yono
* CS 281 - 0798, Fall 2020
* Final Project
*
*******************************************************************************
*/

#ifndef APP_H
#define APP_H

constexpr int PLAYER_DEFEATED = -1;

#include "Room.h"
#include "Player.h"
#include "Treasure.h"
#include "Weapon.h"
#include "Bogey.h"

extern Room* g_pPrisonCell;
extern Room* g_pInfirmary;
extern Room* g_pKitchen;
extern Room* g_pShowers;
extern Room* g_pYard;

Room* initPrisonCell();
Room* initInfirmary();
Room* initKitchen();
Room* initShowers();
Room* initYard();

void initRoomMap();

bool grabTreasure(Player* pP, Room* pR, std::vector<std::string>& msgQ);
bool dropTreasure(Player* pP, Room* pR, std::vector<std::string>& msgQ);
bool grabWeapon(Player* pP, Room* pR, std::vector<std::string>& msgQ);
bool dropWeapon(Player* pP, Room* pR, std::vector<std::string>& msgQ);
char attackGuard(Player* pP, Room* pR, std::vector<std::string>& msgQ);
bool lookAllDirections(Room* pR, std::vector<std::string>& msgQ);
Room* movePlayer(Player* pP, Room* pR, int direction, std::vector<std::string>& msgQ);
bool visitRoom(Player* pP, Room* pR, std::vector<std::string>& msgQ);
bool grabMagicWord(Player* pP, Room* pR, std::vector<std::string>& msgQ);
bool hasMagicWord(Player* pP);



int getInventory(Container* pR, std::vector<std::string>& msgQ);
bool getInfo(Player* pP, Room* pR, std::vector<std::string>& msgQ);
bool getAllInfo(Player* pP, Room* pR, std::vector<std::string>& msgQ);

#endif

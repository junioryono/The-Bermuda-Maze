/******************************************************************************
*
* Amer Yono
* CS 281 - 0798, Fall 2020
* Final Project
*
*******************************************************************************
*/

// include external libraries
#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <cstdlib>

// include internal libraries
#include "app.h"

/******************************************************************************
* Initialize
*******************************************************************************
*/
void displayMessageQueue(std::vector<std::string>& msgQueue);
int mapMoveCommand(char cmd);
char menuOption();

Room* g_pPrisonCell = nullptr;
Room* g_pInfirmary = nullptr;
Room* g_pKitchen = nullptr;
Room* g_pShowers = nullptr;
Room* g_pYard = nullptr;
/******************************************************************************
* End
*******************************************************************************
*/


/******************************************************************************
* int main() | start
*******************************************************************************
*/
int main()
{

    // Initialize messageQueue 
    std::vector<std::string> messageQueue;

    // Initialize all rooms
    g_pPrisonCell = initPrisonCell();
    g_pInfirmary = initInfirmary();
    g_pKitchen = initKitchen();
    g_pShowers = initShowers();
    g_pYard = initYard();

    // Initialize map
    initRoomMap();

    // Set room equal to Prison Cell Room
    Room* pRoom = g_pPrisonCell;

    // Initialize to string
    std::string str;
    std::string playerFirstName;

    // Game title
    std::cout << "The Bermuda Maze\n";

    // Ask for playerFirstName
    std::cout << "\nWhat's your first name?\n";
    std::cin >> playerFirstName;

    // Introduce the player to the game
    std::cout << "\nWelcome " << playerFirstName << ". " << "If you don't remember, you were flying over the Bermuda Triangle. You were knocked out for a while.\n";
    std::cout << "You got kidnapped and are now trapped inside this prison. You have to find a way out of here.\n";

    // Initialize a new player
    Player* pPlayer = new Player(playerFirstName, PLAYER_LIVES);

    // Initialize player inside Prison Cell Room
    visitRoom(pPlayer, pRoom, messageQueue);

    // Initialize getting player points
    int currentPlayerPoints = pPlayer->getPoints();

    // Get player weapons and magic words
    getInventory(pRoom, messageQueue);

    // Display messageQueue for current room
    displayMessageQueue(messageQueue);

    char userCmd;
    int direction;
    int pointsToWinGame = 400;

    Room* pNextRoom = nullptr;

    do
    {
        // Get Current Player Points
        currentPlayerPoints = pPlayer->getPoints();

        if (currentPlayerPoints >= pointsToWinGame)
            userCmd = 'q';
        else 
            userCmd = menuOption();
        

        direction = mapMoveCommand(userCmd);
        if (direction != ROOM_DEAD_END)
            pRoom = movePlayer(pPlayer, pRoom, direction, messageQueue);
        else if (userCmd == 'l')
            lookAllDirections(pRoom, messageQueue);
        else if (userCmd == 'g')
            grabTreasure(pPlayer, pRoom, messageQueue);
        else if (userCmd == 'r')
            dropTreasure(pPlayer, pRoom, messageQueue);
        else if (userCmd == 't')
            grabWeapon(pPlayer, pRoom, messageQueue);
        else if (userCmd == 'b')
            userCmd = attackGuard(pPlayer, pRoom, messageQueue);
        else if (userCmd == 'o')
            dropWeapon(pPlayer, pRoom, messageQueue);
        else if (userCmd == 'i')
            getAllInfo(pPlayer, pRoom, messageQueue);
        else if (userCmd == 'm')
            grabMagicWord(pPlayer, pRoom, messageQueue);
        else if (userCmd == 'q')
            messageQueue.push_back("We hope you return soon.");
        else
            messageQueue.push_back("\aUnknown command.");

        displayMessageQueue(messageQueue);

        // do the above loop while the user doesn't type in q in the command menu
        // and while the current player points is not enough to win the game
    } while (userCmd != 'q' && currentPlayerPoints < pointsToWinGame);

    getInfo(pPlayer, pRoom, messageQueue);

    if (currentPlayerPoints >= pointsToWinGame)
        messageQueue.push_back("YOU BEAT THE GAME! CONGRATS!\n");
        
    messageQueue.push_back("Thank you for playing, " + playerFirstName + "!\n");
    displayMessageQueue(messageQueue);

    system("pause");

    return 0;
}

void displayMessageQueue(std::vector<std::string>& msgQ)
{
    std::cout << std::endl;

    for (std::string msg : msgQ)
        std::cout << msg << "\n";

    msgQ.clear();
 }

int mapMoveCommand(char command)
{
    if (command == 'w')
        return ROOM_UP;   
    if (command == 's')
        return ROOM_DOWN;
    if (command == 'a')
        return ROOM_LEFT;
    if (command == 'd')
        return ROOM_RIGHT;

    return ROOM_DEAD_END;
}

char menuOption()
{
    char cmd;

    std::cout << "Type in the value inside the parenthesis to perform its action." << std::endl;
    std::cout << "(L) Look around you\n";
    std::cout << "(W) Up | (A) Left | (S) Down | (D) Right\n";
    std::cout << "(G) Get treasure | (R) Drop treasure,\n";
    std::cout << "(T) Take weapon | (O) Drop weapon,\n";
    std::cout << "(M) Get Magic Word | (B) Attack Guard,\n";
    std::cout << "(I) Info | (Q)uit\n";
    std::cout << "\nYour next move: ";

    std::cin >> cmd;
    
    cmd = tolower(cmd);

    return cmd;
}


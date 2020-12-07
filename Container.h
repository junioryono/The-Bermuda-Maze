/******************************************************************************
*
* Amer Yono
* CS 281 - 0798, Fall 2020
* Final Project
*
*******************************************************************************
*/

#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include <vector>

#include "Treasure.h"
#include "Weapon.h"
#include "MagicWord.h"
#include "Bogey.h"

constexpr int ROOM_CONTAINER    = 'R';
constexpr int PLAYER_CONTAINER  = 'P';
constexpr int GENERIC_CONTAINER = 'C';

class Container : public Element
{
protected:
    std::vector<Treasure*> m_pTreasureV;
    std::vector<Weapon*> m_pWeaponV;
    std::vector<MagicWord*> m_pMagicWordV;
    std::vector<Bogey*> m_pBogeyV;

public:
    Container();
    Container(const Container& rhsC);

    int addTreasure(Treasure* pT);
    Treasure* removeTreasure();
    Treasure* selectTreasure(const std::string& tName);
    int getTreasureCount() const;
    int getTreasureInfo(std::vector<Treasure*>& pTV);
    void removeAllTreasure();

    int addWeapon(Weapon* pT);
    Weapon* removeWeapon();
    Weapon* selectWeapon(const std::string& wName);
    int getWeaponCount() const;
    int getWeaponInfo(std::vector<Weapon*>& pWV);
    void removeAllWeapon();

    int addMagicWord(MagicWord* pT);
    MagicWord* removeMagicWord();
    MagicWord* selectMagicWord(const std::string& wName);
    int getMagicWordCount() const;
    int getMagicWordInfo(std::vector<MagicWord*>& pWV);
    void removeAllMagicWord();

    int addBogey(Bogey* pB);
    Bogey* removeBogey();
    Bogey* selectBogey(const std::string& bName);
    int getBogeyCount() const;
    int getBogeyInfo(std::vector<Bogey*>& pBV);
    void removeAllBogey();

    bool operator== (const Container& rhsC);

private:
    template <class I>
    int getItemInfo(std::vector<I*>& pDstIV,
                    std::vector<I*>& pSrcIV);

    template <class I>
    int addItem(I* pItem, std::vector<I*>& pIV);

    template <class I>
    I* removeItem(std::vector<I*>& pIV);

    template <class I>
    I* selectItem(const std::string& iName, std::vector<I*>& pIV);

};

#endif

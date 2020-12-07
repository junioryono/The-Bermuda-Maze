/******************************************************************************
*
* Amer Yono
* CS 281 - 0798, Fall 2020
* Final Project
*
*******************************************************************************
*/

#ifndef MAGICWORD_H
#define MAGICWORD_H

#include <string>
#include "CarryIt.h"

int constexpr MAGICWORD_POINTS = 100;
int constexpr MAGICWORD_USES = 1;

class MagicWord : public CarryIt
{
private:
    int m_usesRemaining;

    static int m_mWCount;

public:
    MagicWord();
    MagicWord(const std::string& mWName, int points);

    static int getMagicWordCount();

    int setUsesRemaining(int uses);
    int getUsesRemaining() const;
    int addUsesRemaining(int uses);
};

#endif

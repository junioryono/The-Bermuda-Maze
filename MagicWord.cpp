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

// include internal libraries
#include "MagicWord.h"

int MagicWord::m_mWCount = 0;

MagicWord::MagicWord(const std::string& mWName, int points)
{
    m_mWCount++;

    m_id = MAGICWORD_CARRYIT;
    m_name = mWName;
    m_points = points;
}

MagicWord::MagicWord() : MagicWord("MagicWord", MAGICWORD_POINTS) { }

int MagicWord::getMagicWordCount() { return m_mWCount; }

int MagicWord::setUsesRemaining(int uses)
{
    return m_usesRemaining = uses;
}

int MagicWord::getUsesRemaining() const
{
    return m_usesRemaining;
}

int MagicWord::addUsesRemaining(int uses)
{
    return m_usesRemaining += uses;
}

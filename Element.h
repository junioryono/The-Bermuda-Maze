/******************************************************************************
*
* Amer Yono
* CS 281 - 0798, Fall 2020
* Final Project
*
*******************************************************************************
*/

#ifndef ELEMENT_H
#define ELEMENT_H

int constexpr GENERIC_ELEMENT = 'e';

class Element
{
protected:
    int m_id;
    std::string m_name;
    std::string m_text;
    int m_points;

public:
    Element();

    int getId() const;
    
    void setName(const std::string& name);
    std::string& getName(std::string& name) const;
    
    int addPoints(int points);
    void setPoints(int points);
    int getPoints() const;

    void setText(const std::string& text);
    std::string& getText(std::string& text) const;
};

#endif
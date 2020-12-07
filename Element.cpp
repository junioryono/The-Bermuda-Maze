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
#include "Element.h"

Element::Element() 
{ 
    m_points = 0; 
    m_id = GENERIC_ELEMENT;
}

int Element::getId() const { return m_id; }

void Element::setName(const std::string& name) 
{ m_name = name; }

std::string& Element::getName(std::string& name) const
{ return name = m_name; }

void Element::setPoints(int points) { m_points = points; }

int Element::getPoints() const { return m_points; }

int Element::addPoints(int points)
{ return m_points += points; }

void Element::setText(const std::string& text)
{ m_text = text; }

std::string& Element::getText(std::string& text) const
{ return text = m_text; }


/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu()
{
    this->_beg_b1 = { 554  , 239 };
    this->_end_b1 = { 1268 , 384 };

    this->_beg_b2 = { 554  , 442 };
    this->_end_b2 = { 1268 , 587 };

    this->_beg_b3 = { 554  , 645 };
    this->_end_b3 = { 1268 , 790 };

    this->_beg_b4 = { 554  , 848 };
    this->_end_b4 = { 1268 , 993 };

    _tex = new sf::Texture();
    _tex->loadFromFile("assets/Menu.png");
    _spt.setTexture(*_tex, false);
}

Menu::~Menu()
{
    if (_tex)
        delete _tex;
}
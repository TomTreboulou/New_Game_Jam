/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Spawner
*/

#include "Building.hpp"

Spawner::Spawner(int x, int y, std::string name, float MoneyFactor, float WoodFactor, float StoneFactor, float IronFactor, int lvl, int type) : Building(x, y, std::string("Spawner"), MoneyFactor, WoodFactor, StoneFactor, IronFactor, lvl)
{
    this->_type = type;
    this->_delay = 10.0;
}

bool
Spawner::_generatePnj()
{
    if (this->_pnjs.size() < this->_level * 5 && \
        this->_clock.getElapsedTime().asSeconds() >= this->_delay)
    {
        this->_pnjs.push_back(*this);
        this->_clock.restart();
        return (true);
    }
    return (false);
}

void
Spawner::managePnjs(sf::RenderWindow *window)
{
    Pnj *tmp = nullptr;

    for (std::size_t i = 0; i < this->_pnjs.size(); ++i) {
        window->draw(this->_pnjs.at(i).getSprite());
        if (this->_pnjs.at(i).movePnj())
            this->_pnjs.erase(this->_pnjs.begin() + i);
    } 
}

void
Spawner::Update(int &money, int &wood, int &stone, int &iron)
{
    if ((money >= (this->_moneyFactor * this->_level)) && (wood >= (this->_woodFactor * this->_level)) && (stone >= (this->_stoneFactor * this->_level)) && (iron >= (this->_ironFactor * this->_level))) {
        money -= (this->_moneyFactor * this->_level);
        wood -= (this->_woodFactor * this->_level);
        stone -= (this->_stoneFactor * this->_level);
        iron -= (this->_ironFactor * this->_level);
        this->_valid = true;
        this->_level += 1;
        this->_delay = 10 / this->_level;
    } else {

    }
}
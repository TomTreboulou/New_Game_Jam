/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Spawner
*/

#include "Building.hpp"
#include <iostream>

//std::map<int, Building *> &
std::vector<Building *> &
Spawner::DestinationWrapper(std::map<std::string, Building *> &buildings, bool get)
{
    static std::vector<Building *> destination;

    if (get && destination.size() < 3) {
        if (buildings["Market"] && buildings["Market"]->getLevel())
            destination.push_back(buildings["Market"]);
        if (buildings["Hotel"] && buildings["Hotel"]->getLevel())
            destination.push_back(buildings["Hotel"]);
        if (buildings["Restaurant"] && buildings["Restaurant"]->getLevel())
            destination.push_back(buildings["Restaurant"]);
        std::sort(destination.begin(), destination.end() );
        destination.erase( unique( destination.begin(), destination.end() ), destination.end() );
    }

    return destination;
}

Spawner::Spawner(int x, int y, std::string name, float MoneyFactor, float WoodFactor, float StoneFactor, float IronFactor, int lvl, int type) : Building(x, y, std::string("Spawner"), MoneyFactor, WoodFactor, StoneFactor, IronFactor, lvl)
{
    this->_type = type;
    this->_delay = (5 + this->_level) / this->_level;
}

bool
Spawner::generatePnj(Building *build)
{
    if (this->_pnjs.size() < build->getLevel() * 40 && \
        this->_clock.getElapsedTime().asSeconds() >= this->_delay)
    {
        this->_pnjs.push_back( Pnj(*build, this->_type, (sf::IntRect){0, 0, 80, 131}) );
        this->_clock.restart();
        return (true);
    }
    return (false);
}

void
Spawner::managePnjs(sf::RenderWindow *window, std::map<std::string, Building *> &destination, sf::Vector2f &mov)
{
    if (!DestinationWrapper(destination, true).empty()) {
        int val = DestinationWrapper(destination, false).size();
        this->generatePnj(DestinationWrapper(destination, false).at(rand() % val));
    }
    for (std::size_t i = 0; i < this->_pnjs.size(); ++i) {
        this->_pnjs.at(i).draw(window, mov);
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
        this->_delay = (5 + this->_level) / this->_level;
    } else {

    }
}

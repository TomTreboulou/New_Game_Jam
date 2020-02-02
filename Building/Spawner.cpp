/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Spawner
*/

#include "Building.hpp"
#include <iostream>

std::map<int, Building *> &
Spawner::DestinationWrapper(std::map<std::string, Building *> &buildings, bool get)
{
    static std::map<int, Building *> destination;

std::cerr<<"\n\tDestinaTionWrapper: size("<<destination.size()<<": \n";
std::cerr<<"-market["<<buildings["Market"]->getLevel()<<"]\n";
std::cerr<<"--Hotel["<<buildings["Hotel"]->getLevel()<<"]\n";
std::cerr<<"---Restaurant["<<buildings["Restaurant"]->getLevel()<<"]\n";
    if (get && destination.size() < 3) {
        if (buildings["Market"]->getLevel())
            destination[MARKET] = buildings["Market"];
        if (buildings["Hotel"]->getLevel())
            destination[HOSTEL] = buildings["Hotel"];
        if (buildings["Restaurant"]->getLevel())
            destination[RESTAURANT] = buildings["Restaurant"];
    }
std::cerr<<"\tDestinaTionWrapper before quit: size("<<destination.size()<<": \n";
    return destination;
}

Spawner::Spawner(int x, int y, std::string name, float MoneyFactor, float WoodFactor, float StoneFactor, float IronFactor, int lvl, int type) : Building(x, y, std::string("Spawner"), MoneyFactor, WoodFactor, StoneFactor, IronFactor, lvl)
{
    this->_type = type;
    this->_delay = 1.0;
    this->_maxPnjs = 0;
}

bool
Spawner::generatePnj(Building *build)
{
std::cerr<<"generatePNJ: ";
    if (this->_pnjs.size() < this->_maxPnjs && \
        this->_clock.getElapsedTime().asSeconds() >= this->_delay)
    {
std::cerr<<"before gen...";
        this->_pnjs.push_back( Pnj(*build, this->_type) );
std::cerr<<"end gen";
        this->_clock.restart();
        return (true);
    }
    return (false);
}

void
Spawner::managePnjs(sf::RenderWindow *window, std::map<std::string, Building *> &destination)
{
std::cerr<<"managePnjs: ";
    if (!DestinationWrapper(destination, true).empty()) {
        int val = DestinationWrapper(destination, false).size();
        this->generatePnj(DestinationWrapper(destination, false)[rand() % val]);
    }
std::cerr<<"end generatePNJ\n";
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
        this->_maxPnjs = this->_level * 5;
    } else {

    }
}
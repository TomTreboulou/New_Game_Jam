/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Building
*/

#include "Building.hpp"

Building::Building(int x, int y, std::string name, float MoneyFactor, float WoodFactor, float StoneFactor, float IronFactor, int lvl)
{
    this->_pos.x = x;
    this->_pos.y = y;
    this->_name = name;
    this->_valid = false;
    this->_woodFactor = WoodFactor;
    this->_moneyFactor = MoneyFactor;
    this->_stoneFactor = StoneFactor;
    this->_ironFactor = IronFactor;
    this->_level = lvl;
    this->_value = 0;
    if (this->_level == 0)
        this->tex.loadFromFile("./assets/ruine.png");
    else
        this->tex.loadFromFile("./assets/" + name + ".png");
    this->spr.setTexture(this->tex, false);
    this->spr.setPosition(this->_pos);
}

Building::~Building()
{
}

bool Building::isValid() const
{
    return (this->_valid);
}

sf::Vector2f Building::getPos() const
{
    return (this->_pos);
}

int Building::getLevel() const
{
    return (this->_level);
}

std::string Building::getName() const
{
    return this->_name;
}

int Building::getValue() const
{
    return this->_value;
}

std::vector<int> Building::getCost() const
{
    std::vector<int> cost;

    cost.push_back((this->_moneyFactor * (this->_level + 1)));
    cost.push_back((this->_woodFactor * (this->_level + 1)));
    cost.push_back((this->_stoneFactor * (this->_level + 1)));
    cost.push_back((this->_ironFactor * (this->_level + 1)));
    return (cost);
}

void Building::Update(int &money, int &wood, int &stone, int &iron)
{
    if ((money >= (this->_moneyFactor * (this->_level + 1))) && (wood >= (this->_woodFactor * (this->_level + 1))) && (stone >= (this->_stoneFactor * (this->_level + 1))) && (iron >= (this->_ironFactor * (this->_level + 1)))) {
        if (!this->_level)
            this->tex.loadFromFile("./assets/" + this->_name + ".png");
        money -= (this->_moneyFactor * (this->_level + 1));
        wood -= (this->_woodFactor * (this->_level + 1));
        stone -= (this->_stoneFactor * (this->_level + 1));
        iron -= (this->_ironFactor * (this->_level + 1));
        this->_valid = true;
        this->_level += 1;
        this->_value = (this->_moneyFactor / 50);
    } else {

    }
}

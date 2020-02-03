/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Building
*/

#include "Building.hpp"
#include "../Game/Game.hpp"

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
    this->_value = (this->_level > 0) ? (this->_moneyFactor / 10) : 0;
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

void Building::generate()
{
    if (this->isValid() && _clock.getElapsedTime().asSeconds() > 2) {
        if (this->getName() == "Forge") {
            player.setIron(2 * this->_level);
        } else if (this->getName() == "LumberMill") {
            player.setWood(3 * this->_level);
        } else if (this->getName() == "Quarry") {
            player.setStone(3 * this->_level);
        }
        _clock.restart();
    }
}

std::vector<int> Building::getCost() const
{
    std::vector<int> cost;

    cost.push_back((this->_moneyFactor * (this->_level + 1)));
    cost.push_back((this->_woodFactor * (this->_level + 1)));
    cost.push_back((this->_stoneFactor * (this->_level + 1)));
    if (this->_level >= 5) {
        cost.push_back((this->_ironFactor * (this->_level - 4)));
    } else if (this->_level >= 1 && this->getName() == "Forge") {
        cost.push_back((this->_ironFactor * (this->_level)));
    } else {
        cost.push_back(0);
    }
    return (cost);
}

void Building::Update()
{
    if ((player.getMoney() >= (this->_moneyFactor * (this->_level + 1))) && (player.getWood() >= (this->_woodFactor * (this->_level + 1))) && (player.getStone() >= (this->_stoneFactor * (this->_level + 1))) && (this->getLevel() < 5 || player.getIron() >= (this->_ironFactor * (this->_level - 4)))) {
        if (this->_level >= 1 && this->_level <= 5 && this->getName() == "Forge" && player.getIron() < (this->_ironFactor * (this->_level))) {
            return;
        }
        if (!this->_level) {
            player.sound->create->sound.play();
            this->tex.loadFromFile("./assets/" + this->_name + ".png");
            this->spr.setTexture(this->tex, false);
            this->spr.setTextureRect((sf::IntRect){0, 0, (int)this->tex.getSize().x, (int)this->tex.getSize().y});
        }
        player.sound->upgrade->sound.play();
        player.setMoney(-1 * (this->_moneyFactor * (this->_level + 1)));
        player.setWood(-1 * (this->_woodFactor * (this->_level + 1)));
        player.setStone(-1 * (this->_stoneFactor * (this->_level + 1)));
        if (this->_level >= 5) {
            player.setIron(-1 * (this->_ironFactor * (this->_level - 4)));
        } else if (this->getName() == "Forge") {
            player.setIron(-1 * (this->_ironFactor * (this->_level)));
        }
        this->_valid = true;
        this->_level += 1;
        this->_value = ((this->_moneyFactor * (this->_level + 1) / 30));
    } else {

    }
}

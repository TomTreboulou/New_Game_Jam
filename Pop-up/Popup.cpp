/*
** EPITECH PROJECT, 2020
** New_Game_Jam
** File description:
** Popup
*/

#include "Popup.hpp"

Line::Line(std::string font, sf::Vector2f pos, std::vector<int> cost)
{
    this->_cost_money = cost[0];
    this->_cost_wood = cost[1];
    this->_cost_stone = cost[2];
    this->font_money.loadFromFile(font);
    this->font_stone.loadFromFile(font);
    this->font_wood.loadFromFile(font);
    this->cost_money.setFont(this->font_money);
    this->cost_stone.setFont(this->font_stone);
    this->cost_wood.setFont(this->font_wood);
    this->cost_money.setCharacterSize(50);
    this->cost_stone.setCharacterSize(50);
    this->cost_wood.setCharacterSize(50);
    this->cost_money.setPosition(pos);
    this->cost_money.setPosition((sf::Vector2f){pos.x + 330, pos.y});
    this->cost_money.setPosition((sf::Vector2f){pos.x + 650, pos.y});
}

void Line::updateCost(std::vector<int> cost)
{
    this->_cost_money = cost[0];
    this->_cost_wood = cost[1];
    this->_cost_stone = cost[2];
}

Popup::Popup(std::map<std::string, Building *> &buildings)
{
    this->_buildings = buildings;
    this->Forge = new Line("../assets/Signatra.ttf", {500, 140}, buildings["Forge"]->getCost());
    this->Market = new Line("../assets/Signatra.ttf", {500, 310}, buildings["Market"]->getCost());
    this->Hotel = new Line("../assets/Signatra.ttf", {500, 470}, buildings["Hotel"]->getCost());
    this->Quarry = new Line("../assets/Signatra.ttf", {500, 620}, buildings["Quarry"]->getCost());
    this->Restaurant = new Line("../assets/Signatra.ttf", {500, 770}, buildings["Restaurant"]->getCost());
}

Popup::~Popup()
{
}

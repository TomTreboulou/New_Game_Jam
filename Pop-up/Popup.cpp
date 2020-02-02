/*
** EPITECH PROJECT, 2020
** New_Game_Jam
** File description:
** Popup
*/

#include "Popup.hpp"

Line::Line(std::string str, sf::Vector2f pos, std::vector<int> cost)
{
    this->_cost_money = cost[0];
    this->_cost_wood = cost[1];
    this->_cost_stone = cost[2];
    this->font_money.loadFromFile(str);
    this->font_stone.loadFromFile(str);
    this->font_wood.loadFromFile(str);
    this->cost_money.setFont(this->font_money);
    this->cost_stone.setFont(this->font_stone);
    this->cost_wood.setFont(this->font_wood);
    this->cost_money.setCharacterSize(50);
    this->cost_stone.setCharacterSize(50);
    this->cost_wood.setCharacterSize(50);
    this->cost_money.setPosition(pos);
    this->cost_money.setPosition((sf::Vector2f){pos.x + 330, pos.y});
    this->cost_money.setPosition((sf::Vector2f){pos.x + 650, pos.y});
    this->box_pos = {1390, pos.y};
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
    std::cout << "Forge" << std::endl;
    this->Market = new Line("assets/Signatra.ttf", {500, 140}, buildings["Market"]->getCost());
    std::cout << "Market" << std::endl;
    this-> = new Line("assets/Signatra.ttf", {500, 310}, buildings["Restaurant"]->getCost());
    std::cout << "Hotel" << std::endl;
    this->Hotel = new Line("assets/Signatra.ttf", {500, 470}, buildings["Hotel"]->getCost());
    std::cout << "Quarry" << std::endl;
    this->Quarry = new Line("assets/Signatra.ttf", {500, 620}, buildings["Quarry"]->getCost());
    std::cout << "Restaurant" << std::endl;
    this->Restaurant = new Line("assets/Signatra.ttf", {500, 770}, buildings["Restaurant"]->getCost());
    std::cout << "end" << std::endl;
    this->tex.loadFromFile("assets/Popup.png");
    this->spr.setTexture(this->tex, false);
}

Popup::~Popup()
{
}

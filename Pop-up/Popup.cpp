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
    this->cost_wood.setPosition((sf::Vector2f){pos.x + 330, pos.y});
    this->cost_stone.setPosition((sf::Vector2f){pos.x + 650, pos.y});
    this->cost_money.setString(std::to_string(cost[0]));
    this->cost_wood.setString(std::to_string(cost[1]));
    this->cost_stone.setString(std::to_string(cost[2]));
    this->box_pos = {1390, pos.y};
}

void Line::updateCost(std::vector<int> cost)
{
    this->_cost_money = cost[0];
    this->_cost_wood = cost[1];
    this->_cost_stone = cost[2];
    this->cost_money.setString(std::to_string(cost[0]));
    this->cost_wood.setString(std::to_string(cost[1]));
    this->cost_stone.setString(std::to_string(cost[2]));
}

void Popup::DrawAll(sf::RenderWindow *window)
{
    window->draw(this->Hotel->cost_money);
    window->draw(this->Hotel->cost_stone);
    window->draw(this->Hotel->cost_wood);
    window->draw(this->Market->cost_money);
    window->draw(this->Market->cost_stone);
    window->draw(this->Market->cost_wood);
    window->draw(this->Restaurant->cost_money);
    window->draw(this->Restaurant->cost_stone);
    window->draw(this->Restaurant->cost_wood);
    window->draw(this->LumberMill->cost_money);
    window->draw(this->LumberMill->cost_stone);
    window->draw(this->LumberMill->cost_wood);
    window->draw(this->Quarry->cost_money);
    window->draw(this->Quarry->cost_stone);
    window->draw(this->Quarry->cost_wood);
    window->draw(this->Forge->cost_money);
    window->draw(this->Forge->cost_stone);
    window->draw(this->Forge->cost_wood);
}

Popup::Popup(std::map<std::string, Building *> &buildings)
{
    this->_buildings = buildings;
    this->Market = new Line("assets/Signatra.ttf", {500, 140}, this->_buildings["Market"]->getCost());
    this->Restaurant = new Line("assets/Signatra.ttf", {500, 310}, this->_buildings["Restaurant"]->getCost());
    this->Hotel = new Line("assets/Signatra.ttf", {500, 470}, this->_buildings["Hotel"]->getCost());
    this->LumberMill = new Line("assets/Signatra.ttf", {500, 620}, this->_buildings["LumberMill"]->getCost());
    this->Quarry = new Line("assets/Signatra.ttf", {500, 770}, this->_buildings["Quarry"]->getCost());
    this->Forge = new Line("assets/Signatra.ttf", {500, 910}, this->_buildings["Forge"]->getCost());
    this->tex.loadFromFile("assets/Popup.png");
    this->spr.setTexture(this->tex, false);
}

Popup::~Popup()
{
}

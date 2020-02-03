/*
** EPITECH PROJECT, 2020
** New_Game_Jam
** File description:
** Popup
*/

#include "Popup.hpp"

Line::Line(std::string str, sf::Vector2f pos, std::vector<int> cost, int level, bool side)
{
    this->_cost_money = cost[0];
    this->_cost_wood = cost[1];
    this->_cost_stone = cost[2];
    this->_cost_iron = cost[3];
    this->_level = "level: " + std::to_string(level);
    this->font_money.loadFromFile(str);
    this->font_wood.loadFromFile(str);
    this->font_stone.loadFromFile(str);
    this->font_iron.loadFromFile(str);
    this->font_level.loadFromFile(str);
    this->cost_money.setFont(this->font_money);
    this->cost_wood.setFont(this->font_wood);
    this->cost_stone.setFont(this->font_stone);
    this->cost_iron.setFont(this->font_iron);
    this->level.setFont(this->font_level);
    this->cost_money.setCharacterSize(50);
    this->cost_wood.setCharacterSize(50);
    this->cost_stone.setCharacterSize(50);
    this->cost_iron.setCharacterSize(50);
    this->level.setCharacterSize(50);
    this->cost_money.setPosition(pos);
    this->cost_wood.setPosition((sf::Vector2f){pos.x, pos.y + 75});
    this->cost_stone.setPosition((sf::Vector2f){pos.x, pos.y + 150});
    this->cost_iron.setPosition((sf::Vector2f){pos.x, pos.y + 225});
    this->cost_money.setString(std::to_string(cost[0]));
    this->cost_wood.setString(std::to_string(cost[1]));
    this->cost_stone.setString(std::to_string(cost[2]));
    this->cost_iron.setString(std::to_string(cost[3]));
    this->level.setString(this->_level);
    if (side) {
        this->box_pos = {pos.x + 190, pos.y + 135};
        this->level.setPosition((sf::Vector2f){pos.x + 205, pos.y + 85});
    } else {
        this->box_pos = {pos.x - 175, pos.y + 135};
        this->level.setPosition((sf::Vector2f){pos.x - 160, pos.y + 85});
    }
}

void Line::updateCost(std::vector<int> cost, int level)
{
    this->_cost_money = cost[0];
    this->_cost_wood = cost[1];
    this->_cost_stone = cost[2];
    this->_cost_iron = cost[3];
    this->_level = "level: " + std::to_string(level);
    this->cost_money.setString(std::to_string(cost[0]));
    this->cost_wood.setString(std::to_string(cost[1]));
    this->cost_stone.setString(std::to_string(cost[2]));
    this->cost_iron.setString(std::to_string(cost[3]));
    this->level.setString(this->_level);
}

void Popup::DrawAll(sf::RenderWindow *window)
{
    window->draw(this->Hotel->cost_money);
    window->draw(this->Hotel->cost_wood);
    window->draw(this->Hotel->cost_stone);
    window->draw(this->Hotel->cost_iron);
    window->draw(this->Hotel->level);
    window->draw(this->Market->cost_money);
    window->draw(this->Market->cost_wood);
    window->draw(this->Market->cost_stone);
    window->draw(this->Market->cost_iron);
    window->draw(this->Market->level);
    window->draw(this->Restaurant->cost_money);
    window->draw(this->Restaurant->cost_wood);
    window->draw(this->Restaurant->cost_stone);
    window->draw(this->Restaurant->cost_iron);
    window->draw(this->Restaurant->level);
    window->draw(this->LumberMill->cost_money);
    window->draw(this->LumberMill->cost_wood);
    window->draw(this->LumberMill->cost_stone);
    window->draw(this->LumberMill->cost_iron);
    window->draw(this->LumberMill->level);
    window->draw(this->Quarry->cost_money);
    window->draw(this->Quarry->cost_wood);
    window->draw(this->Quarry->cost_stone);
    window->draw(this->Quarry->cost_iron);
    window->draw(this->Quarry->level);
    window->draw(this->Forge->cost_money);
    window->draw(this->Forge->cost_wood);
    window->draw(this->Forge->cost_stone);
    window->draw(this->Forge->cost_iron);
    window->draw(this->Forge->level);
}

Popup::Popup(std::map<std::string, Building *> &buildings)
{
    this->_buildings = buildings;
    this->Market = new Line("assets/Signatra.ttf", {925, 85}, this->_buildings["Market"]->getCost(),this->_buildings["Market"]->getLevel(), false);
    this->Restaurant = new Line("assets/Signatra.ttf", {925, 385}, this->_buildings["Restaurant"]->getCost(),this->_buildings["Restaurant"]->getLevel(), false);
    this->Hotel = new Line("assets/Signatra.ttf", {925, 690}, this->_buildings["Hotel"]->getCost(),this->_buildings["Hotel"]->getLevel(), false);
    this->Quarry = new Line("assets/Signatra.ttf", {1210, 85}, this->_buildings["Quarry"]->getCost(),this->_buildings["Quarry"]->getLevel(), true);
    this->LumberMill = new Line("assets/Signatra.ttf", {1210, 385}, this->_buildings["LumberMill"]->getCost(),this->_buildings["LumberMill"]->getLevel(), true);
    this->Forge = new Line("assets/Signatra.ttf", {1210, 690}, this->_buildings["Forge"]->getCost(),this->_buildings["Forge"]->getLevel(), true);
    this->tex.loadFromFile("assets/Popup.png");
    this->spr.setTexture(this->tex, false);
}

Popup::~Popup()
{
}

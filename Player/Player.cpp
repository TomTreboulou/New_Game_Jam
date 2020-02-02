/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Player
*/

#include "Player.hpp"
#include <iostream>

std::string Player::getName()
{
    return (this->_name);
}

int Player::getMoney()
{
    return (this->_money);
}

int Player::getWood()
{
    return (this->_wood);
}

int Player::getStone()
{
    return (this->_stone);
}

int Player::getIron()
{
    return (this->_iron);
}

void Player::setMoney(int value)
{
    this->_money += value;
    this->money->text.setString(std::to_string(this->_money));
}

void Player::setWood(int value)
{
    this->_wood += value;
    this->wood->text.setString(std::to_string(this->_wood));
}

void Player::setStone(int value)
{
    this->_stone += value;
    this->stone->text.setString(std::to_string(this->_stone));
}

void Player::setIron(int value)
{
    this->_iron += value;
    this->iron->text.setString(std::to_string(this->_iron));
}

Ressource::Ressource(std::string str, sf::Vector2f pos, sf::Vector2f _pos)
{
    this->tex.loadFromFile(str);
    this->sprite.setTexture(this->tex, false);
    this->sprite.setPosition(pos);
    this->font.loadFromFile("assets/Signatra.ttf");
    this->text.setFont(this->font);
    this->text.setCharacterSize(50);
    this->text.setPosition(_pos);
}

Player::Player()
{
    this->_money = 100;
    this->_iron = 0;
    this->_stone = 0;
    this->_wood = 0;
    this->money = new Ressource("assets/money.png", (sf::Vector2f){0, 0}, (sf::Vector2f){150, 42});
    this->wood = new Ressource("assets/wood.png", (sf::Vector2f){350, 0}, (sf::Vector2f){500, 42});
    this->stone = new Ressource("assets/stone.png", (sf::Vector2f){700, 0}, (sf::Vector2f){850, 42});
    this->iron = new Ressource("assets/iron.png", (sf::Vector2f){1050, 0}, (sf::Vector2f){1200, 42});
    this->sound = new Sound();
    this->money->text.setString(std::to_string(this->_money));
    this->wood->text.setString(std::to_string(this->_wood));
    this->stone->text.setString(std::to_string(this->_stone));
    this->iron->text.setString(std::to_string(this->_iron));
}

Player::~Player()
{
}

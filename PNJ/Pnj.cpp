/*
** EPITECH PROJECT, 2020
** Pnj.cpp
** File description:
** Pnj
*/

#include "Pnj.hpp"
#include "../Game/Game.hpp"
#include <iostream>

Pnj::Pnj(Building &build, bool type, sf::IntRect box)
{
    this->_map_idx = 0;
    this->_clock = sf::Clock();
    this->_clock_rect = sf::Clock();
    this->_target = &build;

    this->_index_rect = 0;
    this->_texture = new sf::Texture();
    this->_box = box;
    this->_texture->loadFromFile("assets/Sprite_" + std::to_string(rand() % 3) + ".png");
    this->_spt.setTexture(*this->_texture, false);
    this->_spt.setTextureRect(this->_box);

    if (!build.getName().compare("Market")) {
        if (type) {
            this->_map = {{1765,1440}, {1475, 1440}, {1475, 975}, {1640, 975}, {1640, 900}};
        } else {
            this->_map = {{1115, 1475}, {1115, 1540}, {1475, 1540}, {1475, 975}, {1640, 975}, {1640, 900}};
        }
    }
    else if (!build.getName().compare("Restaurant")) {
        if (type) {
            this->_map = {{1765,1440}, {1475,1440}, {1475, 2060}, {1215, 2060}, {1215, 1870}};
        } else {
            this->_map = {{1115, 1475}, {1115, 1540}, {1475, 1540}, {1475, 2060}, {1215, 2060}, {1215, 1870}};
        }
    }
    else if (!build.getName().compare("Hotel")) {
        if (type) {
            this->_map = {{1765,1440}, {1990, 1440}, {1990, 2025}, {1705, 2025}, {1705, 1915}};
        } else {
            this->_map = {{1115, 1475}, {1115, 1540}, {1475, 1540}, {1475, 2025}, {1705, 2025}, {1705, 1915}};
        }
    }
    this->_pos.x = this->_map[0].x - this->_box.width / 2;
    this->_pos.y = this->_map[0].y - this->_box.height / 1.2;
    this->_setMove();
}

Pnj::~Pnj()
{
}

void
Pnj::_setMove(void)
{
    for (std::size_t idx = 1; idx < this->_map.size(); ++idx) {
        if ( this->_map[idx].x != this->_map[idx - 1].x ) {
            if ( this->_map[idx].x > this->_map[idx - 1].x ) {
                this->_movement.push_back(sf::Vector2f(3, 0));
            } else {
                this->_movement.push_back(sf::Vector2f(-3, 0));
            }
        } else {
            if ( this->_map[idx].y > this->_map[idx - 1].y ) {
                this->_movement.push_back(sf::Vector2f(0, 3));
            } else {
                this->_movement.push_back(sf::Vector2f(0, -3));
            }
        }
    }
}


void Pnj::update_x(float x) {
	this->_pos.x += x;
	this->_spt.setPosition(this->_pos);
	if (x > 0)
        this->_box.left = (this->_index_rect + 4) * 79;
    else
        this->_box.left = (this->_index_rect + 12) * 79;
    if (!x || this->_clock_rect.getElapsedTime().asSeconds() < 0.16)
        return;
    this->_clock_rect.restart();
    this->_spt.setTextureRect(this->_box);
    this->_index_rect = (this->_index_rect >= 3) ? 0 : this->_index_rect + 1;
}
void Pnj::update_y(float y) {
	this->_pos.y += y;
	this->_spt.setPosition(this->_pos);
    if (!y || this->_clock_rect.getElapsedTime().asSeconds() < 0.16)
        return;
    this->_clock_rect.restart();
    if (y > 0)
        this->_box.left = (this->_index_rect) * 79;
    else
        this->_box.left = (this->_index_rect + 8) * 79;
    this->_spt.setTextureRect(this->_box);
    this->_index_rect = (this->_index_rect >= 3) ? 0 : this->_index_rect + 1;
}

void
Pnj::_setPos(void)
{
    this->update_x(this->_movement[this->_map_idx].x);
    this->update_y(this->_movement[this->_map_idx].y);
}

void
Pnj::_targetReached()
{
    player.sound->piece->sound.play();
    player.setMoney(this->_target->getValue());
}

bool
Pnj::movePnj(void)
{
    if (_clock.getElapsedTime().asSeconds() > 0.016) {
        _setPos();
        if ((_pos.x + _box.width / 2) >= _map[_map_idx + 1].x - 3 && \
            (_pos.x + _box.width / 2) <= _map[_map_idx + 1].x + 3 && \
            (_pos.y + _box.height / 1.2) >= _map[_map_idx + 1].y - 3 && \
            (_pos.y + _box.height / 1.2) <= _map[_map_idx + 1].y + 3)
        {
            ++_map_idx;
            if (_map_idx >= _map.size() - 1) {
                _targetReached();
                player.env->icon_click_money.set_pos((sf::Vector2f){(float)(_map[_map_idx].x - 30), (float)(_map[_map_idx].y - 150)}, (sf::Vector2f){(float)(_map[_map_idx].x + 2), (float)(_map[_map_idx].y - 100)});
                for (int i = 0; i < this->_target->getLevel() && i < 10; i++)
                    player.env->icon_click_money.add();
                return true;
            }
            _pos.x = _map[_map_idx].x - this->_box.width / 2;
            _pos.y = _map[_map_idx].y - this->_box.height / 1.2;
        }
        _clock.restart();
    }
    return false;
}

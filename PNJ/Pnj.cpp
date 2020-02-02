/*
** EPITECH PROJECT, 2020
** Pnj.cpp
** File description:
** Pnj
*/

#include "Pnj.hpp"

Pnj::Pnj(Building &build, bool type)
{
    this->_map_idx = 1;
    this->_clock = sf::Clock();
    this->_target = &build;

    this->_texture.loadFromFile("../assets/pnj.png");
    this->_spt.setTexture(this->_texture, false);


    if (!build.getName().compare("Market")) {
        if (type) {
            this->_map = {{1765,1440}, {1475, 1440}, {1475, 975}, {1640, 975}, {1640, 900}};
        } else {
            this->_map = {{1115, 1475}, {1115, 1540}, {1475, 1540}, {1475, 975}, {1640, 975}, {1640, 900}};
        }
    }
    else if (!build.getName().compare("Restaurant")) {
        if (type) {
            this->_map = {{1765,1440}, {1475,1440}, {1475, 2060}, {1215, 2016}, {1215, 1870}};
        } else {
            this->_map = {{1115, 1475}, {1115, 1540}, {1475, 1540}, {1475, 2060}, {1215, 2016}, {1215, 1870}};
        }
    }
    else if (!build.getName().compare("Hostel")) {
        if (type) {
            this->_map = {{1765,1440}, {1990, 1440}, {1990, 2025}, {1705, 2025}, {1705, 1915}};
        } else {
            this->_map = {{1115, 1475}, {1115, 1540}, {1475, 1540}, {1475, 2025}, {1705, 2025}, {1705, 1915}};
        }
    }
    this->_pos = this->_map[0];
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
                this->_movement.push_back(sf::Vector2i(6, 0));
            } else {
                this->_movement.push_back(sf::Vector2i(-6, 0));
            }
        } else {
            if ( this->_map[idx].y > this->_map[idx - 1].y ) {
                this->_movement.push_back(sf::Vector2i(0, 6));
            } else {
                this->_movement.push_back(sf::Vector2i(0, -6));
            }
        }
    }
}

void
Pnj::_targetReached(void)
{
    // get ressource;
}

void
Pnj::_setPos(void)
{
    this->_pos.x += this->_movement[this->_map_idx].x;
    this->_pos.y += this->_movement[this->_map_idx].y;
    /*
        if (_animClock.getElapsedTime().asSecond() > 0.5) {
            // make anim;
            _animClock.restart();
        }
    */
}

bool
Pnj::movePnj(void)
{
    if (_clock.getElapsedTime().asSeconds() > /*0.34*/0.8) {

        if (_movement[_map_idx].x) {
            if (_movement[_map_idx].x > 0) {
                if (_map[_map_idx + 1].x >= _pos.x) {
                    ++_map_idx;
                    if (_map_idx >= _map.size()) {
                        _targetReached();
                        return true;
                    }
                    _pos = _map[_map_idx];
                }
                _setPos();

            } else {

                if (_map[_map_idx + 1].x <= _pos.x) {
                    ++_map_idx;
                    if (_map_idx >= _map.size()) {
                        _targetReached();
                        return true;
                    }
                    _pos = _map[_map_idx];
                }
                _setPos();

            }
        } else {

            if (_movement[_map_idx].y > 0) {
                if (_map[_map_idx + 1].y >= _pos.y) {
                    ++_map_idx;
                    if (_map_idx >= _map.size()) {
                        _targetReached();
                        return true;
                    }
                    _pos = _map[_map_idx];
                }
                _setPos();

            } else {

                if (_map[_map_idx + 1].y <= _pos.y) {
                    ++_map_idx;
                    if (_map_idx >= _map.size()) {
                        _targetReached();
                        return true;
                    }
                    _pos = _map[_map_idx];
                }
                _setPos();

            }
        }
        _clock.restart();
    }
    return false;
}
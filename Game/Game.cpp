/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Game
*/

#include "Game.hpp"

Game::Game(std::string file)
{
    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    this->window = new sf::RenderWindow(modes[0], GAME_NAME, sf::Style::Fullscreen);
    this->window->setFramerateLimit(60);
}

Game::~Game()
{
}

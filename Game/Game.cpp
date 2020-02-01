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
    Parser::Parser_XML parser;

    this->movement = {0, 0};
    this->status = true;
    this->move = false;
    this->click = false;
	parser.load_file("Config/map1.xml");
	for (Parser_Tree *node = parser.getChild("building"); node; node = node->getNextChild()) {
        if (node->getAttribut("id") != "") {
            Spawner *building = new Spawner(stoi(node->getAttribut("x")), stoi(node->getAttribut("y")), node->getAttribut("name"), stof(node->getAttribut("MoneyFactor")), stof(node->getAttribut("WoodFactor")), stof(node->getAttribut("StoneFactor")), stof(node->getAttribut("IronFactor")), stoi(node->getAttribut("lvl")), stoi(node->getAttribut("id")));
            this->buildings[node->getAttribut("name")] = building;
        } else {
            Building *building = new Building(stoi(node->getAttribut("x")), stoi(node->getAttribut("y")), node->getAttribut("name"), stof(node->getAttribut("MoneyFactor")), stof(node->getAttribut("WoodFactor")), stof(node->getAttribut("StoneFactor")), stof(node->getAttribut("IronFactor")), stoi(node->getAttribut("lvl")));
            this->buildings[node->getAttribut("name")] = building;
        }
	}
    this->window = new sf::RenderWindow(modes[0], GAME_NAME, sf::Style::Fullscreen);
    //this->window = new sf::RenderWindow(modes[0], GAME_NAME);
    this->window->setFramerateLimit(60);
    this->window->setMouseCursorVisible(false);
	this->tex_mouse.loadFromFile("./assets/cursor.png");
    this->spr_mouse.setTexture(this->tex_mouse, false);
    this->tex_back.loadFromFile("./assets/background.png");
    this->background.setTexture(this->tex_back, false);
    this->last = sf::Mouse::getPosition();
}

Game::~Game()
{
    for(auto it = this->buildings.begin(); it != this->buildings.end(); it++) {
        delete it->second;
    }
}

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
    this->status = 0;
    this->move = false;
    this->click = false;
	parser.load_file(file);
	for (Parser_Tree *node = parser.getChild("building"); node; node = node->getNextChild()) {
        if (node->getAttribut("id") != "") {
            Spawner *building = new Spawner(stoi(node->getAttribut("x")), stoi(node->getAttribut("y")), node->getAttribut("name"), stof(node->getAttribut("MoneyFactor")), stof(node->getAttribut("WoodFactor")), stof(node->getAttribut("StoneFactor")), stof(node->getAttribut("IronFactor")), stoi(node->getAttribut("lvl")), stoi(node->getAttribut("id")));
            this->buildings[node->getAttribut("name")] = building;
        } else {
            Building *building = new Building(stoi(node->getAttribut("x")), stoi(node->getAttribut("y")), node->getAttribut("name"), stof(node->getAttribut("MoneyFactor")), stof(node->getAttribut("WoodFactor")), stof(node->getAttribut("StoneFactor")), stof(node->getAttribut("IronFactor")), stoi(node->getAttribut("lvl")));
            this->buildings[node->getAttribut("name")] = building;
        }
	}
    this->popup = new Popup(this->buildings);
    this->menu = new Menu();
    //this->window = new sf::RenderWindow(modes[0], GAME_NAME, sf::Style::Fullscreen);
    this->icon_wood = Icon(15, (sf::Vector2f){1160, 0}, (sf::Vector2f){2555, 600}, "assets/icon_wood.png", true, false);
    this->icon_stone = Icon(5, (sf::Vector2f){160, 160}, (sf::Vector2f){800, 500}, "assets/icon_stone.png", true, false);

    this->icon_click_wood = Icon(0, (sf::Vector2f){0, 0}, (sf::Vector2f){0, 0}, "assets/icon_wood.png", false, false);
    this->icon_click_stone = Icon(0, (sf::Vector2f){0, 0}, (sf::Vector2f){0, 0}, "assets/icon_stone.png", false, false);
    this->icon_click_money = Icon(0, (sf::Vector2f){0, 0}, (sf::Vector2f){0, 0}, "assets/icon_coin.png", false, true);

    this->window = new sf::RenderWindow(modes[0], GAME_NAME, sf::Style::Fullscreen);
    this->window->setFramerateLimit(60);
    this->window->setMouseCursorVisible(false);
	this->tex_mouse.loadFromFile("./assets/cursor.png");
    this->spr_mouse.setTexture(this->tex_mouse, false);
    this->tex_back.loadFromFile("./assets/background.png");
    this->background.setTexture(this->tex_back, false);
    this->last = sf::Mouse::getPosition();
    player.env = this;
}

void Game::save(const std::string &file)
{
    int i = 1;
    std::ofstream myStream(file);
    myStream << "<game>\n";
    for (auto it = this->buildings.begin(); it != this->buildings.end(); it++) {
        if (it->second->getName().find("Spawner") <= 0) {
            myStream << "\t<building name=\"" << it->second->getName() << std::to_string(i) << "\" x=\"" << (int)it->second->getPos().x << "\" y=\"" << (int)it->second->getPos().y << "\" MoneyFactor=\"" << it->second->getMoneyFactor() << "\" WoodFactor=\"" <<  it->second->getWoodFactor() << "\" StoneFactor=\"" << it->second->getStoneFactor() << "\" IronFactor=\"" << it->second->getIronFactor() << "\" lvl=\"" << it->second->getLevel() << "\" id=\"" << i - 1 << "\"></building>\n";
            i++;
        } else {
            myStream << "\t<building name=\"" << it->second->getName() << "\" x=\"" << (int)it->second->getPos().x << "\" y=\"" << (int)it->second->getPos().y << "\" MoneyFactor=\"" << it->second->getMoneyFactor() << "\" WoodFactor=\"" <<  it->second->getWoodFactor() << "\" StoneFactor=\"" << it->second->getStoneFactor() << "\" IronFactor=\"" << it->second->getIronFactor() << "\" lvl=\"" << it->second->getLevel() << "\"></building>\n";
        }
    }
    myStream << "\t<player money=\"" << player.getMoney() << "\" wood=\"" << player.getWood() << "\" stone=\"" << player.getStone() << "\" iron=\"" << player.getIron() << "\"></player>\n";
    myStream << "</game>\n";
    myStream.close();
}

void Game::load(const std::string &file)
{
    Parser::Parser_XML parser;

    this->buildings.clear();
    parser.load_file(file);
    for (Parser_Tree *node = parser.getChild("building"); node; node = node->getNextChild()) {
        if (node->getAttribut("id") != "") {
            Spawner *building = new Spawner(stoi(node->getAttribut("x")), stoi(node->getAttribut("y")), node->getAttribut("name"), stof(node->getAttribut("MoneyFactor")), stof(node->getAttribut("WoodFactor")), stof(node->getAttribut("StoneFactor")), stof(node->getAttribut("IronFactor")), stoi(node->getAttribut("lvl")), stoi(node->getAttribut("id")));
            this->buildings[node->getAttribut("name")] = building;
        } else {
            Building *building = new Building(stoi(node->getAttribut("x")), stoi(node->getAttribut("y")), node->getAttribut("name"), stof(node->getAttribut("MoneyFactor")), stof(node->getAttribut("WoodFactor")), stof(node->getAttribut("StoneFactor")), stof(node->getAttribut("IronFactor")), stoi(node->getAttribut("lvl")));
            this->buildings[node->getAttribut("name")] = building;
        }
	}
    this->popup = new Popup(this->buildings);
    Parser_Tree *player_node = parser.getChild("player");
    if (player_node) {
        player.setMoney(stoi(player_node->getAttribut("money")) - player.getMoney());
        player.setWood(stoi(player_node->getAttribut("wood")) - player.getWood());
        player.setStone(stoi(player_node->getAttribut("stone")) - player.getStone());
        player.setIron(stoi(player_node->getAttribut("iron")) - player.getIron());
    }
}

Game::~Game()
{
    for(auto it = this->buildings.begin(); it != this->buildings.end(); it++) {
        delete it->second;
    }
}

/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <map>
#include "Utile.hpp"
#include "../Player/Player.hpp"
#include "../Building/Building.hpp"
#include "../Config/ParserTree.hpp"
#include "../Config/ParserXML.hpp"
#include "../PNJ/Pnj.hpp"
#include "Icon.hpp"
#include "../Pop-up/Popup.hpp"

#define GAME_NAME "Idle World"

class Player;
class Building;
class Popup;
class Icon;

class Game {
	public:
		Game(std::string file = "Config/map1.yml");
		~Game();
		////
        sf::RenderWindow *window;
        sf::Event event;
		////

		sf::Texture tex_back;
		sf::Sprite background;
		////

		sf::Vector2f movement;
		sf::Vector2i actual;
		sf::Vector2i last;
		bool move;
		bool click;

		sf::Vector2i mouse;
		sf::Texture tex_mouse;
		sf::Sprite spr_mouse;
		////

        std::map<std::string, Building *> buildings;
		////

		int status;

		Icon icon_wood;
		Icon icon_stone;

		Popup *popup;
	protected:
	private:
};

extern Player player;

#endif /* !GAME_HPP_ */
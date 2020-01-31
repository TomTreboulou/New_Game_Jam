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
#include "../Building/Building.hpp"

#define GAME_NAME "Idle World"

class Game {
	public:
		Game(std::string file = "Config/map1.yml");
		~Game();
        sf::RenderWindow *window;
        sf::Event event;
        std::map<std::string, Building *> buildings;

	protected:
	private:
};

#endif /* !GAME_HPP_ */

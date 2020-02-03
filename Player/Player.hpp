/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <map>
#include "../Sound/Sound.hpp"
#include "../Game/Game.hpp"

class Game;
class Sound;

class Ressource {
	public:
		Ressource(std::string str, sf::Vector2f pos, sf::Vector2f);
		sf::Font font;
    	sf::Text text;
		sf::Sprite sprite;
		sf::Texture tex;
	protected:
	private:
};

class Player {
	public:
		Player();
		~Player();
		std::string getName();
		int getMoney();
		int getWood();
		int getStone();
		int getIron();
		void setMoney(int v);
		void setWood(int v);
		void setStone(int v);
		void setIron(int v);
		Ressource *money;
		Ressource *iron;
		Ressource *wood;
		Ressource *stone;
		Sound *sound;
		sf::Font font;
    	sf::Text text;
		int click;
		Game *env;

	protected:
	private:
    	int _money;
    	int _wood;
    	int _stone;
    	int _iron;
		std::string _name;
};

#endif /* !PLAYER_HPP_ */

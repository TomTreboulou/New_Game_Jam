/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Icon
*/

#ifndef ICON_HPP_
#define ICON_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

class Icon {
	public:
		Icon() {};
		Icon(int i, sf::Vector2f pos1, sf::Vector2f pos2, const std::string &file, bool update, bool up) {
            this->_pos1 = pos1;
            this->_pos2 = pos2;
			this->_file = file;
			this->_update = update;
			this->_up = up;
			for (int j = 0; j < i; j++)
				this->add();
		};
        ~Icon() {
			// for (auto it = this->_icon.begin() ; it < this->_icon.end(); it++) {
			// 	delete (*it);
			// }
		};
		class Img {
			public:
				sf::Texture tex;
				sf::Sprite spr;
				sf::Vector2f pos;
				unsigned char color;
				Img(sf::Vector2f pos1, sf::Vector2f pos2, const std::string &file) {
					this->tex.loadFromFile(file);
		    		this->spr.setTexture(this->tex, false);
					this->color = rand() % 200 + 50;
					this->spr.setColor(sf::Color(255, 255, 255, this->color));
					pos.x = pos1.x + rand() % (int)(abs(pos2.x - pos1.x) + 1);
					pos.y = pos1.y + rand() % (int)(abs(pos2.y - pos1.y) + 1);
					this->spr.setPosition(this->pos);
				}
		};
		void add() {
			this->_icon.push_back(new Img(this->_pos1, this->_pos2, this->_file));
		};
		void set_pos(sf::Vector2f pos1, sf::Vector2f pos2) {
			this->_pos1 = pos1;
            this->_pos2 = pos2;
		}
		void update() {
			for (auto it = this->_icon.begin() ; it < this->_icon.end(); it++) {
				(*it)->color--;
				if (!this->_up)
					(*it)->pos.y += rand() % 2 ? 1 : 0;
				else
					(*it)->pos.y -= rand() % 2 ? 1 : 0;
				if ((*it)->color <= 0) {
					delete (*it);
					this->_icon.erase(it);
					if (this->_update)
						this->add();
				} else {
					(*it)->spr.setColor(sf::Color(255, 255, 255, (*it)->color));
					(*it)->spr.setPosition((*it)->pos);
				}
			}
		};
		void draw(sf::RenderWindow *window) {
			for (auto it = this->_icon.begin() ; it < this->_icon.end(); it++) {
				window->draw((*it)->spr);
			}
		};
		std::vector<Img *> _icon;
	private:
		std::string _file;
		sf::Vector2f _pos1;
		sf::Vector2f _pos2;
		bool _update;
		bool _up;
};

#endif /* !ICON_HPP_ */

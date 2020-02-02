/*
** EPITECH PROJECT, 2020
** Pnj.hpp
** File description:
** Pnj
*/

#ifndef PNJ_HPP_
#define PNJ_HPP_

#include "../Building/Building.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <map>

class Building;

class Pnj {
	public:
                Pnj(Building &build, bool type);
		~Pnj();

                bool    movePnj(void);

                // setter
                void         setSpritePos(sf::Vector2f &mov)
                {
                        this->_spt.setPosition({this->_pos.x + mov.x, this->_pos.y + mov.y});
                };
                // Getter
                std::size_t  getIdx(void)    const {return _map_idx;};
                sf::Vector2f getPos(void)    const {return _pos;};
                void         draw(sf::RenderWindow *window, sf::Vector2f &mov)
                {
                        setSpritePos(mov);
                        window->draw(this->_spt);
                };

	protected:
	private:
                void    _setMove(void);
                void    _targetReached(void);
                void    _setPos(void);

                std::vector<sf::Vector2f> _map;       // etape a atteindre
                std::vector<sf::Vector2f> _movement;
                sf::Vector2f    _pos;       // position du pnj
                std::size_t     _map_idx;   // index de l'etape en cour
                Building        *_target;   // building a atteindre
                sf::Texture     _texture;
                sf::Sprite      _spt;
                sf::Clock       _clock;
};

#endif /* !PNJ_HPP_ */

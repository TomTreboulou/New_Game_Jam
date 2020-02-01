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
                Pnj(Spawner &build, bool type);
		~Pnj();

                bool    movePnj(void);

                // Getter
                std::size_t  getIdx(void)    const {return _map_idx;};
                sf::Vector2i getPos(void)    const {return _pos;};
                sf::Sprite   getSprite(void) const {return _spt;};

	protected:
	private:
                void    _setMove(void);
                void    _targetReached(void);
                void    _setPos(void);

                std::vector<sf::Vector2i> _map;       // etape a atteindre
                std::vector<sf::Vector2i> _movement;
                sf::Vector2i    _pos;       // position du pnj
                std::size_t     _map_idx;   // index de l'etape en cour
                Building        _target;   // building a atteindre
               sf::Texture     _texture;
               sf::Sprite      _spt;
               sf::Clock       _clock;
};

#endif /* !PNJ_HPP_ */

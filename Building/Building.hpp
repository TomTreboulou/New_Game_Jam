/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Building
*/

#ifndef BUILDING_HPP_
#define BUILDING_HPP_

#include "../PNJ/Pnj.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <map>

class Pnj;

class Building {
	public:
		Building(int x, int y, std::string name, float MoneyFactor, float WoodFactor, float StoneFactor, float IronFactor, int lvl);
		virtual ~Building();
                virtual bool isValid() const;
                virtual void Update(int &money, int &wood, int &stone, int &iron);
                virtual int               getLevel() const;
                virtual sf::Vector2f      getPos() const;
                virtual std::vector<int>  getCost() const;
                virtual std::string       getName() const;
                virtual int               getValue() const;

                sf::Texture       tex;
		sf::Sprite        spr;
	protected:
                sf::Vector2f    _pos;

                std::string     _name;
                bool            _valid;
                int             _level;

                float           _value;
                float           _moneyFactor;
                float           _woodFactor;
                float           _stoneFactor;
                float           _ironFactor;
	private:
};

class Spawner : public Building {
        public:
                enum dest {MARKET, HOSTEL, RESTAURANT};
                Spawner(int x, int y, std::string name, float MoneyFactor, float WoodFactor, float StoneFactor, float IronFactor, int lvl, int type);

                void    managePnjs(sf::RenderWindow *window, std::map<std::string, Building *> &destination, sf::Vector2f &mov);

                // setter
                void    Update(int &money, int &wood, int &stone, int &iron);
                // getter
                bool    getType() const {return _type;};

                bool    generatePnj(Building *build);
                std::vector<Building *> &DestinationWrapper(std::map<std::string, Building *> &buildings, bool get);
        protected:

                bool                    _type;
                std::vector<Pnj>        _pnjs;
                double                  _delay;
                sf::Clock               _clock;

};

class Generator : public Building {
        public:
        protected:
        private:
};

#endif /* !BUILDING_HPP_ */

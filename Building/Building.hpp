/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Building
*/

#ifndef BUILDING_HPP_
#define BUILDING_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <map>

class Building {
	public:
		Building(int x, int y, std::string name, float MoneyFactor, float WoodFactor, float StoneFactor, float IronFactor);
		~Building();
        bool isValid() const;
        int getLevel() const;
        sf::Vector2f getPos() const;
        std::vector<int> getCost() const;
        void Update(int &money, int &wood, int &stone, int &iron);

	protected:
	private:
        sf::Vector2f _pos;
        std::string _name;
        bool _valid;
        int _level;
        float _moneyFactor;
        float _woodFactor;
        float _stoneFactor;
        float _ironFactor;
};

#endif /* !BUILDING_HPP_ */

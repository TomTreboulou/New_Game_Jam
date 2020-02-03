/*
** EPITECH PROJECT, 2020
** New_Game_Jam
** File description:
** Popup
*/

#ifndef POPUP_HPP_
#define POPUP_HPP_

#include "../Game/Game.hpp"

class Building;

class Line {
    public:
        Line(std::string path2, sf::Vector2f pos, std::vector<int> cost, int level, bool side);
        void updateCost(std::vector<int> cost, int level);
        sf::Vector2f box_pos;
        sf::Font font_stone;
        sf::Font font_money;
        sf::Font font_wood;
        sf::Font font_iron;
        sf::Font font_level;
        sf::Text cost_stone;
        sf::Text cost_money;
        sf::Text cost_wood;
        sf::Text cost_iron;
        sf::Text level;
    protected:
    private:
        int _cost_money;
        int _cost_wood;
        int _cost_stone;
        int _cost_iron;
        std::string _level;
};

class Popup {
	public:
		Popup(std::map<std::string, Building *> &buildings);
		~Popup();
        void DrawAll(sf::RenderWindow *window);
        Line *Market;
        Line *LumberMill;
        Line *Quarry;
        Line *Restaurant;
        Line *Hotel;
        Line *Forge;
        sf::Texture tex;
        sf::Sprite spr;
        std::map<std::string, Building *> _buildings;

	protected:
	private:
};

#endif /* !POPUP_HPP_ */

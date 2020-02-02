/*
** EPITECH PROJECT, 2020
** New_Game_Jam
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "../Game/Game.hpp"

class Menu {
    public:
        Menu();
        ~Menu();

        void Draw(sf::RenderWindow *window)
        {
            window->draw(_spt);
        };
        bool saveGame(void);
        void quitGame(void);
        sf::Texture  *_tex;
        sf::Sprite _spt;
    
        sf::Vector2i _beg_b1;
        sf::Vector2i _end_b1;;
        
        sf::Vector2i _beg_b2;
        sf::Vector2i _end_b2;
        
        sf::Vector2i _beg_b3;
        sf::Vector2i _end_b3;

        sf::Vector2i _beg_b4;
        sf::Vector2i _end_b4;
        
    protected:
    private:

};

#endif /* !MENU_HPP_ */

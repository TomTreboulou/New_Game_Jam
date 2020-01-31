/*
** EPITECH PROJECT, 2020
** New_Game_Jam
** File description:
** main
*/

#include "./Game/Game.hpp"

void start(Game *game)
{
    while (game->window->isOpen())
    {
        while (game->window->pollEvent(game->event)) {
            if (game->event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                game->window->close();
        }
        game->window->clear();
        game->window->display();
    }
}

int main(void)
{
    Game *game = new Game();
    start(game);
}
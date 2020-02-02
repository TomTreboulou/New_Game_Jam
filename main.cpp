/*
** EPITECH PROJECT, 2020
** New_Game_Jam
** File description:
** main
*/

#include "./Game/Game.hpp"

Player player;

void draw(Game *game)
{
    sf::Vector2i actual = sf::Mouse::getPosition();
    // game->icon_wood.update();
    // game->icon_stone.update();
    game->spr_mouse.setPosition((sf::Vector2f){(float)actual.x, (float)actual.y});
    game->window->draw(game->background);
    for(auto it = game->buildings.begin(); it != game->buildings.end(); it++) {
        it->second->spr.setPosition((sf::Vector2f){game->movement.x + it->second->getPos().x, game->movement.y + it->second->getPos().y});
        game->window->draw(it->second->spr);
    }
    //  for (auto it = game->icon_wood._icon.begin() ; it != game->icon_wood._icon.end(); it++) {
	//  	(*it)->spr.setPosition((sf::Vector2f){game->movement.x + (*it)->pos.x, game->movement.y + (*it)->pos.y});
	//  }
    // for (auto it = game->icon_stone._icon.begin() ; it != game->icon_stone._icon.end(); it++) {
	//  	(*it)->spr.setPosition((sf::Vector2f){game->movement.x + (*it)->pos.x, game->movement.y + (*it)->pos.y});
	//  }
    for (auto it = game->buildings.begin(); it != game->buildings.end(); it++) {
        if (it->first.compare("Spawner") > 0) {
            (static_cast<Spawner *> (it->second))->managePnjs(game->window, game->buildings, game->movement);
        }
    }
    // game->icon_wood.draw(game->window);
    // game->icon_stone.draw(game->window);
    game->window->draw(player.money->sprite);
    game->window->draw(player.money->text);
    game->window->draw(player.wood->sprite);
    game->window->draw(player.wood->text);
    game->window->draw(player.stone->sprite);
    game->window->draw(player.stone->text);
    game->window->draw(player.iron->sprite);
    game->window->draw(player.iron->text);
    game->window->draw(game->spr_mouse);
}

void event_game(Game *game)
{
    sf::Vector2u size = game->window->getSize();
    game->actual = sf::Mouse::getPosition();
    int random = rand() % 10;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && game->actual.y - game->movement.y <= 600 && game->actual.x - game->movement.x >= 1160 && game->click == false)  {
            player.setWood(1);
            game->click = true;
            random = rand() % 10;
            if (random == 1) {
                player.setMoney(1);
            }
    } else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && game->actual.y - game->movement.y <= 600 && game->actual.x - game->movement.x >= 1160) {
        game->click = false;
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && game->actual.y - game->movement.y <= 550 && game->actual.y - game->movement.y >= 160 && game->actual.x - game->movement.x <= 815 && game->actual.x - game->movement.x >= 160 && game->click == false){
        player.setStone(1);
        game->click = true;
        random = rand() % 10;
        if (random == 1) {
            player.setMoney(1);
        }
    } else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && game->actual.y - game->movement.y <= 550 && game->actual.y - game->movement.y >= 160 && game->actual.x - game->movement.x <= 815 && game->actual.x - game->movement.x >= 160){
        game->click = false;
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i tmp = game->last;
        game->movement.x -= abs(game->last.x - game->actual.x) > 1 ? game->last.x - game->actual.x : 0;
        game->movement.y -= abs(game->last.y - game->actual.y) > 1 ? game->last.y - game->actual.y : 0;
        game->movement.x = (game->movement.x >= 0) ? 0 : game->movement.x;
        game->movement.y = (game->movement.y >= 0) ? 0 : game->movement.y;
        game->movement.x = (game->movement.x < -2592 + 1920) ? -2592 + 1920 : game->movement.x;
        game->movement.y = (game->movement.y < -2592 + 1080) ? -2592 + 1080 : game->movement.y;
        game->background.setPosition(game->movement);
    }
    game->last = sf::Mouse::getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        game->status = 1;
    }
    if (game->event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        game->window->close();
}

void the_game(Game *game)
{
    while (game->window->pollEvent(game->event))
        event_game(game);
    draw(game);
    game->window->display();
}

void menu(Game *game)
{
    sf::Vector2i actual = sf::Mouse::getPosition();

    game->spr_mouse.setPosition((sf::Vector2f){(float)actual.x, (float)actual.y});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
        game->status = 0;
    }
    game->window->clear();
    game->window->draw(game->popup->spr);
    game->popup->DrawAll(game->window);
    game->window->draw(game->spr_mouse);
    game->window->display();
}

void start(Game *game)
{
    while (game->window->isOpen())
    {
        if (game->status == 0) {
            the_game(game);
        } else if (game->status == 1) {
            menu(game);
        }
    }
}

int main(void)
{
    Game *game = new Game();
    // Pnj::_texture.loadFromFile("../assets/pnj.png");
    start(game);
    delete(game);
    return (0);
}
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
    game->icon_wood.update();
    game->icon_stone.update();
    game->icon_click_wood.update();
    game->icon_click_stone.update();
    game->spr_mouse.setPosition((sf::Vector2f){(float)actual.x, (float)actual.y});
    game->window->draw(game->background);
    for(auto it = game->buildings.begin(); it != game->buildings.end(); it++) {
        it->second->spr.setPosition((sf::Vector2f){game->movement.x + it->second->getPos().x, game->movement.y + it->second->getPos().y});
        game->window->draw(it->second->spr);
    }
    for (auto it = game->icon_wood._icon.begin() ; it != game->icon_wood._icon.end(); it++) {
	 	(*it)->spr.setPosition((sf::Vector2f){game->movement.x + (*it)->pos.x, game->movement.y + (*it)->pos.y});
	}
    for (auto it = game->icon_stone._icon.begin() ; it != game->icon_stone._icon.end(); it++) {
	 	(*it)->spr.setPosition((sf::Vector2f){game->movement.x + (*it)->pos.x, game->movement.y + (*it)->pos.y});
	}
    for (auto it = game->icon_click_wood._icon.begin() ; it != game->icon_click_wood._icon.end(); it++) {
	 	(*it)->spr.setPosition((sf::Vector2f){game->movement.x + (*it)->pos.x, game->movement.y + (*it)->pos.y});
	}
    for (auto it = game->icon_click_stone._icon.begin() ; it != game->icon_click_stone._icon.end(); it++) {
	 	(*it)->spr.setPosition((sf::Vector2f){game->movement.x + (*it)->pos.x, game->movement.y + (*it)->pos.y});
	}
    for (auto it = game->buildings.begin(); it != game->buildings.end(); it++) {
        if (it->first.compare("Spawner") > 0) {
            (static_cast<Spawner *> (it->second))->managePnjs(game->window, game->buildings, game->movement);
        } else {
            it->second->generate();
        }
    }
    game->icon_wood.draw(game->window);
    game->icon_stone.draw(game->window);
    game->icon_click_wood.draw(game->window);
    game->icon_click_stone.draw(game->window);
    game->window->draw(player.money->sprite);
    game->window->draw(player.money->text);
    game->window->draw(player.wood->sprite);
    game->window->draw(player.wood->text);
    game->window->draw(player.stone->sprite);
    game->window->draw(player.stone->text);
    game->window->draw(player.iron->sprite);
    game->window->draw(player.iron->text);
    game->window->draw(game->spr_mouse);
    if (game->status == 1) {
        game->window->draw(game->popup->spr);
        game->popup->DrawAll(game->window);
        game->window->draw(game->spr_mouse);
    } else if (game->status == 2) {
        game->menu->Draw(game->window);
        game->window->draw(game->spr_mouse);
    }
}

void event_game(Game *game)
{
    sf::Vector2u size = game->window->getSize();
    game->actual = sf::Mouse::getPosition();
    int random = rand() % 10;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && game->actual.y - game->movement.y <= 600 && game->actual.x - game->movement.x >= 1160 && game->click == false)  {
            player.sound->wood->sound.play();
            player.setWood(1);
            game->icon_click_wood.set_pos((sf::Vector2f){(float)(game->actual.x - 30 - game->movement.x), (float)(game->actual.y - 30 - game->movement.y)}, (sf::Vector2f){(float)(game->actual.x + 2 - game->movement.x), (float)(game->actual.y + 2 - game->movement.y)});
            game->icon_click_wood.add();
            game->click = true;
            random = rand() % 10;
            if (random == 1) {
                player.sound->piece->sound.play();
                player.setMoney(1);
            }
    } else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && game->actual.y - game->movement.y <= 600 && game->actual.x - game->movement.x >= 1160) {
        game->click = false;
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && game->actual.y - game->movement.y <= 550 && game->actual.y - game->movement.y >= 160 && game->actual.x - game->movement.x <= 815 && game->actual.x - game->movement.x >= 160 && game->click == false){
        player.sound->stone->sound.play();
        player.setStone(1);
        game->icon_click_stone.set_pos((sf::Vector2f){(float)(game->actual.x - 30 - game->movement.x), (float)(game->actual.y - 30 - game->movement.y)}, (sf::Vector2f){(float)(game->actual.x + 2 - game->movement.x), (float)(game->actual.y + 2 - game->movement.y)});
        game->icon_click_stone.add();
        game->click = true;
        random = rand() % 10;
        if (random == 1) {
            player.sound->piece->sound.play();
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) || sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
        while (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) || sf::Keyboard::isKeyPressed(sf::Keyboard::I));
        game->status = 1;
    }
    if (game->event.type == sf::Event::Closed)
        game->window->close();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        game->status = 2;
}

void achat(Game *game)
{
    sf::Vector2i actual = sf::Mouse::getPosition();

    game->spr_mouse.setPosition((sf::Vector2f){(float)actual.x, (float)actual.y});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) || sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
        while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) || sf::Keyboard::isKeyPressed(sf::Keyboard::I));
        game->status = 0;
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        while(sf::Mouse::isButtonPressed(sf::Mouse::Left));
        if (actual.x >= game->popup->Market->box_pos.x && actual.x <= game->popup->Market->box_pos.x + 260 && actual.y >= game->popup->Market->box_pos.y && actual.y <= game->popup->Market->box_pos.y + 75) {
            game->popup->_buildings["Market"]->Update();
            game->popup->Market->updateCost(game->popup->_buildings["Market"]->getCost());
        } else if (actual.x >= game->popup->LumberMill->box_pos.x && actual.x <= game->popup->LumberMill->box_pos.x + 260 && actual.y >= game->popup->LumberMill->box_pos.y && actual.y <= game->popup->LumberMill->box_pos.y + 75) {
            game->popup->_buildings["LumberMill"]->Update();
            game->popup->LumberMill->updateCost(game->popup->_buildings["LumberMill"]->getCost());
        } else if (actual.x >= game->popup->Quarry->box_pos.x && actual.x <= game->popup->Quarry->box_pos.x + 260 && actual.y >= game->popup->Quarry->box_pos.y && actual.y <= game->popup->Quarry->box_pos.y + 75) {
            game->popup->_buildings["Quarry"]->Update();
            game->popup->Quarry->updateCost(game->popup->_buildings["Quarry"]->getCost());
        } else if (actual.x >= game->popup->Hotel->box_pos.x && actual.x <= game->popup->Hotel->box_pos.x + 260 && actual.y >= game->popup->Hotel->box_pos.y && actual.y <= game->popup->Hotel->box_pos.y + 75) {
            game->popup->_buildings["Hotel"]->Update();
            game->popup->Hotel->updateCost(game->popup->_buildings["Hotel"]->getCost());
        } else if (actual.x >= game->popup->Restaurant->box_pos.x && actual.x <= game->popup->Restaurant->box_pos.x + 260 && actual.y >= game->popup->Restaurant->box_pos.y && actual.y <= game->popup->Restaurant->box_pos.y + 75) {
            game->popup->_buildings["Restaurant"]->Update();
            game->popup->Restaurant->updateCost(game->popup->_buildings["Restaurant"]->getCost());
        } else if (actual.x >= game->popup->Forge->box_pos.x && actual.x <= game->popup->Forge->box_pos.x + 260 && actual.y >= game->popup->Forge->box_pos.y && actual.y <= game->popup->Forge->box_pos.y + 75) {
            game->popup->_buildings["Forge"]->Update();
            game->popup->Forge->updateCost(game->popup->_buildings["Forge"]->getCost());
        } else {

        }
    }
}

void menu(Game *game)
{
    sf::Vector2i actual = sf::Mouse::getPosition();

    game->spr_mouse.setPosition((sf::Vector2f){(float)actual.x, (float)actual.y});
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        while(sf::Mouse::isButtonPressed(sf::Mouse::Left));
        if (actual.x >= game->menu->_beg_b1.x && actual.y >= game->menu->_beg_b1.y && actual.x <= game->menu->_end_b1.x && actual.y <= game->menu->_end_b1.y)
            game->status = 0;
        else if (actual.x >= game->menu->_beg_b2.x && actual.y >= game->menu->_beg_b2.y && actual.x <= game->menu->_end_b2.x && actual.y <= game->menu->_end_b2.y) {
            game->load("Config/save.xml");
            player.sound->create->sound.play();
            game->status = 0;
        } else if (actual.x >= game->menu->_beg_b3.x && actual.y >= game->menu->_beg_b3.y && actual.x <= game->menu->_end_b3.x && actual.y <= game->menu->_end_b3.y) {
            game->save("Config/save.xml");
            player.sound->create->sound.play();
            game->status = 0;
        } else if (actual.x >= game->menu->_beg_b4.x && actual.y >= game->menu->_beg_b4.y && actual.x <= game->menu->_end_b4.x && actual.y <= game->menu->_end_b4.y)
            game->window->close();
    }
}

void start(Game *game)
{
    while (game->window->isOpen())
    {
        if (game->status == 0) {
            while (game->window->pollEvent(game->event))
                event_game(game);
        } else if (game->status == 1) {
            achat(game);
        } else if (game->status == 2) {
            menu(game);
        }
        draw(game);
        game->window->display();
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
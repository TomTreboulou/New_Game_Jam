/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Sound
*/

#include "Sound.hpp"

Son::Son(std::string path)
{
    this->sb.loadFromFile(path);
    this->sound.setBuffer(this->sb);
}

Sound::Sound()
{
    this->piece = new Son("assets/piece.ogg");
    this->wood = new Son("assets/wood_click.ogg");
    this->stone = new Son("assets/stone2.ogg");
    this->stone->sound.setVolume(70);
    this->wood->sound.setVolume(20);
    this->piece->sound.setVolume(20);
    this->upgrade = new Son("assets/orb.ogg");
    this->create = new Son("assets/anvil_use.ogg");
    this->create->sound.setVolume(20);
}

Sound::~Sound()
{
    this->piece->sound.stop();
    this->wood->sound.stop();
    this->stone->sound.stop();
    this->upgrade->sound.stop();
    this->create->sound.stop();
    delete(this->piece);
    delete(this->wood);
    delete(this->stone);
    delete(this->upgrade);
    delete(this->create);
}

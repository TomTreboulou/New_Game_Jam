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
    this->wood = new Son("assets/stone2.ogg");
    this->stone = new Son("assets/wood_click.ogg");
    this->upgrade = new Son("assets/orb.ogg");
}

Sound::~Sound()
{
}

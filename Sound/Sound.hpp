/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include "../Player/Player.hpp"

class Son {
    public:
        Son(std::string path);
        sf::SoundBuffer sb;
        sf::Sound sound;
    private:
    protected:
};

class Sound {
    public:
        Sound();
        ~Sound();
        Son *piece;
        Son *wood;
        Son *stone;
        Son *upgrade;

    protected:
    private:
};

#endif /* !SOUND_HPP_ */

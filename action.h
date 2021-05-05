#ifndef action_H
#define action_H

#include "mainobject.h"
#include "play.h"

class act_ {
public:
    Mix_Chunk* music;
    Mix_Chunk* music1;
    Mix_Music* up;
    Mix_Music* scream;
    Mix_Music* click;
    Mix_Chunk* lose;
    Mix_Chunk* wins;
    SDL_Texture * rel;
    SDL_Texture * menu;
    SDL_Texture *dangod;
    SDL_Texture *die;
    SDL_Texture *win;
    SDL_Texture * next;
    void Set() {
        music = Mix_LoadWAV("bgm.wav");
        music1 = Mix_LoadWAV("stm.wav");
        up = Mix_LoadMUS("up.mp3");
        scream = Mix_LoadMUS("scream.mp3");
        click = Mix_LoadMUS("click.mp3");
        lose = Mix_LoadWAV("lose.wav");
        wins = Mix_LoadWAV("win.wav");
        rel = Map.loadTexture("img/reload.png");
        menu = Map.loadTexture("img/menu.png");
        dangod = Map.loadTexture("img/dangod.png");
        die = Map.loadTexture("img/die.png");
        win = Map.loadTexture("img/win.png");
        next = Map.loadTexture("img/next.png");
    }
    void input_action();
    //Uint32 callback( Uint32 interval, void* param );
    void trap(int X_pos, int Y_pos);
    void trap1(int X_pos, int Y_pos);
    int Play();
};
extern act_ act;
#endif // action_H


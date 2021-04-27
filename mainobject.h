#ifndef mainobject_H
#define mainobject_H

#include <bits/stdc++.h>
#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
using namespace std;
struct PLV{
    int l1;
    int r1;
    int l2;
    int r2;
};
extern PLV pos_lv[10];
class Map_ {
public:
    SDL_Texture* loadTexture(const std::string &file);
    void renderTexture(SDL_Texture *texture, int x, int y, int w, int h);
    void renderTexture(SDL_Texture *texture, int x, int y);
    void load_map();
    void set_plv() {
        int x = 50, y = 50;
        for (int i = 1; i <= 9; i++) {
            pos_lv[i].l1 = x;
            pos_lv[i].r1 = x + 300;
            pos_lv[i].l2 = y;
            pos_lv[i].r2 = y + 100;
            x += 400;
            if (x > 1200) {
                x = 50;
                y += 200;
            }
        }
    }
    void load_data(int level);
    void load_img();
    void RandMap();
    void wel_load();
    void load_level();
    void load_continue();
};


extern const int TILE_SIZE;
extern const int MAX_MAP_X;
extern const int MAX_MAP_Y;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern int x_pos_, y_pos_;
extern SDL_Texture *img[20];
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern bool ok[50];
extern int mat[30][30];
extern SDL_Texture *bg;
extern SDL_Texture *dango;
extern Map_ Map;
#endif


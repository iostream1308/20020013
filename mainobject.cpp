
#include "mainobject.h"

const int TILE_SIZE = 50;
const int MAX_MAP_X = 24;
const int MAX_MAP_Y = 12;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
int x_pos_ = 0, y_pos_ = 450;
SDL_Texture *img[20];
SDL_Window* window;
SDL_Renderer* renderer;
bool ok[50];
int mat[30][30];
PLV pos_lv[10];
SDL_Texture *bg;
SDL_Texture *dango;
Map_ Map;

SDL_Texture* Map_::loadTexture(const std::string &file)
{
    SDL_Texture *texture = nullptr;
	SDL_Surface *loadedImage = IMG_Load(file.c_str());
	if (loadedImage != nullptr){
		texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
	}
	return texture;
}
void Map_::renderTexture(SDL_Texture *texture, int x, int y, int w, int h)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
    dst.w = w;
    dst.h = h;
	SDL_RenderCopy(renderer, texture, NULL, &dst);
}

void Map_::renderTexture(SDL_Texture *texture, int x, int y)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(renderer, texture, NULL, &dst);
}
void Map_::load_img() {
    img[1] = Map.loadTexture("img/gach.png");
    img[2] = Map.loadTexture("img/gai.png");
    img[3] = Map.loadTexture("img/gai1.png");
    img[4] = Map.loadTexture("img/gai2.png");
    img[5] = Map.loadTexture("img/gai3.png");
    img[6] = Map.loadTexture("img/burger.png");
    img[7] = Map.loadTexture("img/ong1.png");
    img[8] = Map.loadTexture("img/ong2.png");
    img[9] = Map.loadTexture("img/hoa.png");

    memset(ok, 0, sizeof(ok));
}
void Map_::RandMap() {
    int t = rand() % 20 + 1;
    string s = "hinh nen/bg";
    string num = "";
    if (t > 9) {
        while(t) {
            num += t % 10 + 48;
            t /= 10;
        }
        reverse(num.begin(), num.end());
    }
    else {
        num += "0";
        num += t + 48;
    }
    s += num + ".jpg";
    bg = Map.loadTexture(s);
    Map.renderTexture(dango, 0, 400, 30, 30);
}
void Map_::load_data(int level) {
    srand(time(NULL));
    string s = "map/map";
    char c = '0' + level;
    s += c;
    s += ".dat";
    ifstream fileInput(s.c_str());
    while(!fileInput.eof()) {
        for (int i = 0; i < MAX_MAP_Y; i++){
            for (int j = 0; j < MAX_MAP_X; j++){
                fileInput >> mat[i][j];
            }
        }
    }
    fileInput.close();
}
void Map_::Lv() {
    for (int i = 1; i <= 9; i++) {
        char c = '0' + i;
        string s = "menu/";
        s += c;
        s += ".PNG";
        lv[i] = loadTexture(s);
    }
}
void Map_::wel_load() {
    SDL_RenderClear(renderer);
    renderTexture(welcome, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    renderTexture(start, 600, 100, 216, 100);
    renderTexture(level, 600, 250, 216, 100);
    renderTexture(quit, 600, 400, 216, 100);
    SDL_RenderPresent(renderer);
}
void Map_::load_level() {
    SDL_RenderClear(renderer);
    renderTexture(bgl, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    for (int i = 1; i <= 9; i++) {
        renderTexture(lv[i], pos_lv[i].l1, pos_lv[i].l2, 300, 100);
    }
    SDL_RenderPresent(renderer);
}



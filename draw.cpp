#include "mainobject.h"
#include "play.h"
#include "draw.h"

void draw_::RenderMap(){
    SDL_RenderClear(renderer);
    Map.renderTexture(bg, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    for (int i = 0; i < MAX_MAP_Y; i++){
        for (int j = 0; j < MAX_MAP_X; j++){
            int pos_y = i*TILE_SIZE;
            int pos_x = j*TILE_SIZE;
            switch (mat[i][j]) {
                case 1: {
                    Map.renderTexture(img[1], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 2: {
                    if(!ok[2])
                        Map.renderTexture(img[1], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 3: {
                    if(!ok[3])
                        Map.renderTexture(img[1], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 4: {
                    if(!ok[4])
                        Map.renderTexture(img[1], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 5: {
                    if(ok[5])
                        Map.renderTexture(img[2], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 6: {
                    if(ok[6])
                        Map.renderTexture(img[2], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 7: {
                    if(ok[7])
                        Map.renderTexture(img[2], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 8: {
                    if(ok[8])
                        Map.renderTexture(img[3], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 9: {
                    if(ok[9])
                        Map.renderTexture(img[3], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 10: {
                    if(ok[10])
                        Map.renderTexture(img[3], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 11: {
                    if(ok[11])
                        Map.renderTexture(img[4], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 12: {
                    if(ok[12])
                        Map.renderTexture(img[4], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 13: {
                    if(ok[13])
                        Map.renderTexture(img[4], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 14: {
                    if(ok[14])
                        Map.renderTexture(img[5], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 15: {
                    if(ok[15])
                        Map.renderTexture(img[5], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 16: {
                    if(ok[16])
                        Map.renderTexture(img[5], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 17: {
                    if(ok[17])
                        Map.renderTexture(img[9], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 18: {
                    if(ok[18])
                        Map.renderTexture(img[9], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 19: {
                    if(ok[19])
                        Map.renderTexture(img[9], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 20: {
                    Map.renderTexture(img[7], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 21: {
                    Map.renderTexture(img[8], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
                case 22: {
                    Map.renderTexture(img[6], pos_x, pos_y, TILE_SIZE, TILE_SIZE);
                    break;
                }
            }
        }
    }
}
void draw_::show_dango() {
    rect_.x = x_pos_ ;
    rect_.y = y_pos_ ;
    SDL_Rect renderQuad = {rect_.x, rect_.y, rect_.w, rect_.h};
    SDL_RenderCopy(renderer, dango, NULL, &renderQuad);
}



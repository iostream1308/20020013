
#include "play.h"
#include "mainobject.h"

SDL_Event e;
int x_val_ = 0, y_val_ = 0;
bool on_ground = 0;
SDL_Rect rect_;


void play_::checkmap() {
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    x1 = (x_pos_ + x_val_) / TILE_SIZE;
    x2 = (x_pos_ + x_val_ + rect_.w - 1) / TILE_SIZE;
    y1 = y_pos_ / TILE_SIZE;
    y2 = (y_pos_ + rect_.h - 1) / TILE_SIZE;
    if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y) {
        if (x_val_ > 0) {
            if (mat[y1][x2] == 1 || mat[y2][x2] == 1 || mat[y1][x2] == 20 || mat[y2][x2] == 20 || mat[y1][x2] == 21 || mat[y2][x2] == 21 || ((mat[y1][x2] == 2 || mat[y2][x2] == 2) && ok[2] == 0) || ((mat[y1][x2] == 3 || mat[y2][x2] == 3)&& ok[3] == 0) || ((mat[y1][x2] == 4 || mat[y2][x2] == 4) && ok[4] == 0)) {
                x_pos_ = x2 * TILE_SIZE;
                x_pos_ -= rect_.w;
                x_val_ = 0;
            }
        }
        else if (x_val_ < 0) {
            if (mat[y1][x1] == 1 || mat[y2][x1] == 1 || mat[y1][x1] == 20 || mat[y2][x1] == 20 || mat[y1][x1] == 21 || mat[y2][x1] == 21 || ((mat[y1][x1] == 2 || mat[y2][x1] == 2) && ok[2] == 0) || ((mat[y1][x1] == 3 || mat[y2][x1] == 3) && ok[3] == 0) || ((mat[y1][x1] == 4 || mat[y2][x1] == 4) && ok[4] == 0)) {
                x_pos_ = (x1 + 1) * TILE_SIZE;
                x_val_ = 0;
            }
        }
    }
    x1 = x_pos_ / TILE_SIZE;
    x2 = (x_pos_ + rect_.w - 1) / TILE_SIZE;
    y1 = (y_pos_ + y_val_) / TILE_SIZE;
    y2 = (y_pos_ + y_val_ + rect_.h - 1) / TILE_SIZE;

    if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y) {
        if (y_val_ > 0) {
            if (mat[y2][x1] == 1 || mat[y2][x2] == 1 || mat[y2][x1] == 20 || mat[y2][x2] == 20 || mat[y2][x1] == 21 || mat[y2][x2] == 21 || ((mat[y2][x1] == 2 || mat[y2][x2] == 2) && ok[2] == 0) || ((mat[y2][x1] == 3 || mat[y2][x2] == 3) && ok[3] == 0) || ((mat[y2][x1] == 4 || mat[y2][x2] == 4) && ok[4] == 0)) {
                y_pos_ = y2 * TILE_SIZE;
                y_pos_ -= rect_.h;
                y_val_ = 0;
                on_ground = true;

            }
        }
        else if (y_val_ < 0) {
            if (mat[y1][x1] == 1 || mat[y1][x2] == 1 || mat[y1][x1] == 20 || mat[y1][x2] == 20 || mat[y1][x1] == 21 || mat[y1][x2] == 21 || ((mat[y1][x1] == 2 || mat[y1][x2] == 2) && ok[2] == 0) || ((mat[y1][x1] == 3 || mat[y1][x2] == 3) && ok[3] == 0) || ((mat[y1][x1] == 4 || mat[y1][x2] == 4) && ok[4] == 0)) {
                y_pos_ = (y1 + 1) * TILE_SIZE;
                y_val_ = 0;
            }
        }
    }
    x_pos_ += x_val_;
    y_pos_ += y_val_;
    if (x_pos_ < 0)
        x_pos_ = 0;
    else if (x_pos_ + rect_.w >= SCREEN_WIDTH) {
        x_pos_ = SCREEN_WIDTH - rect_.w - 1;
    }
    if (y_pos_ < 0)
        y_pos_ = 0;
    else if (y_pos_ + rect_.h >= SCREEN_HEIGHT) {
        y_pos_ = SCREEN_HEIGHT - rect_.h - 1;
    }
}
void play_::do_player() {
    x_val_ = 0;
    y_val_ += 1;
    if (y_val_ >= MAX_FAIL_SPEED)
        y_val_ = MAX_FAIL_SPEED;
    if (input_type_.left_ == 1) {
        x_val_ -= PLAYER_SPEED;
    }

    else if (input_type_.right_ == 1) {
        x_val_ += PLAYER_SPEED;
    }
    if (input_type_.up_ == 1) {
        if (y_pos_ <= 500)
            y_val_ = -PLAYER_SPEED;
    }
    checkmap();
}


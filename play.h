#ifndef play_H
#define play_H
#include "mainobject.h"

#define GRAVITY_SPEED 1
#define MAX_FAIL_SPEED 4
#define PLAYER_SPEED 3

extern SDL_Event e;
extern int x_val_, y_val_;
extern bool on_ground;
extern SDL_Rect rect_;


struct Input{
    int left_;
    int right_;
    int up_;
    int down_;
    int jump_;
};
extern Input input_type_;


class play_ {
public:
    void do_player();
    void checkmap();
    void SetRect() {
        rect_.x = 0;
        rect_.y = 470;
        rect_.h = 30;
        rect_.w = 30;
    }
    void SetInput() {
        input_type_.left_ = 0;
        input_type_.right_ = 0;
        input_type_.down_ = 0;
        input_type_.up_ = 0;
    }

};
extern play_ play;

#endif // play_H



#ifndef action_H
#define action_H

#include "mainobject.h"
#include "play.h"

class act_ {
public:
    void input_action();
    //Uint32 callback( Uint32 interval, void* param );
    void trap(int X_pos, int Y_pos);
    void trap1(int X_pos, int Y_pos);
    int Play();
};
extern act_ act;
#endif // action_H


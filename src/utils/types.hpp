#ifndef __TYPES_HPP__
#define __TYPES_HPP__

struct fPoint{ float x; float y; };

enum Movement {
    NONE = 0
    ,LEFT = 1 << 1
    ,RIGHT = 1 << 2
    ,UP = 1 << 3
    ,DOWN = 1 << 4
};
#endif
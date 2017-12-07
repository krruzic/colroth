#ifndef COLROTH_VIEWPORT_H
#define COLROTH_VIEWPORT_H

namespace Engine {
    template<typename T>
    class Vector2 {
    public:
        T x;
        T y;
    };

    class Viewport {
    public:
        Vector2<int> position;
        Vector2<int> size;
    };
}

#endif

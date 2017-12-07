//Include SDL functions and datatypes

#ifndef EMULATION
#include "3ds.h"
#endif

#include "Colroth.h"

int main(int argc, char **argv) {
    Colroth::Colroth game;
    game.run();
    return 10;
}
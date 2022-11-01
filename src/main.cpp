#include "core/Game.h"

int main(void) {

    Game game;

    while (game.IsRunning())
        game.Update();

    game.close();

    return 0;
}

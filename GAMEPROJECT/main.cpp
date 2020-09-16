#include"Game.h"

int main()
{
    //init rand
    std::srand(static_cast<unsigned>(time(NULL)));

    //Window
    Game game;

    //Game Loop
    while (game.running()) 
    {
        //Update
        game.update();
        //Render
        game.render();
    }


    //End of Application

    return 0;
}
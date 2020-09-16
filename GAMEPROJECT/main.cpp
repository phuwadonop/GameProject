#include"Game.h"

int main()
{
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
#include <iostream>
#include <string>

//Main.pp
int main()
{
	srand(time(NULL));

	Game game;
	game.initGame();

	while (game.getPlaying())
	{
		game.mainMenu();
	}

	return 0;
}

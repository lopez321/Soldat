/*
 *
 *	To projekt samej gry
 *
 */
#include "Scene.h"
#include "Menu.h"

int main()
{	
	Scene *game = new Menu();
	game->run();
	return 0;
}


#ifndef TextButton_h
#define TextButton_h

#include "MainWindow.h"
/* * * * * * * * * * *
 *
 *	Poniewa¿ przyda nam siê pewnie sporo przycisków tekstowych,
 *	a SFML nie ma czegoœ takiego, to rozszerzy³em klasê Text,
 *	¿eby mo¿na by³o sprawdziæ czy myszka jest nad przyciskiem
 *	i czy zosta³ klikniêty.
 *
 * * * * * * * * * * */
class TextButton : public sf::Text, public MainWindow
{
public:
	bool isButtonClicked();
	bool isButtonHover();
};


#endif // !TextButton_h

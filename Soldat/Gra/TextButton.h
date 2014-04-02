#ifndef TextButton_h
#define TextButton_h

#include "MainWindow.h"
/* * * * * * * * * * *
 *
 *	Poniewa� przyda nam si� pewnie sporo przycisk�w tekstowych,
 *	a SFML nie ma czego� takiego, to rozszerzy�em klas� Text,
 *	�eby mo�na by�o sprawdzi� czy myszka jest nad przyciskiem
 *	i czy zosta� klikni�ty.
 *
 * * * * * * * * * * */
class TextButton : public sf::Text, public MainWindow
{
public:
	bool isButtonClicked();
	bool isButtonHover();
};


#endif // !TextButton_h

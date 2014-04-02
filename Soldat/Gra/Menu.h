#ifndef Menu_h
#define Menu_h

#include <SFML\Audio.hpp>

#include "Scene.h"
#include "TextButton.h"
/* * * * * * * * * * *
 *
 *	Pierwszy i podstawowy widok gry. Nie b�dziemy si� 
 *	wysila� za bardzo i chyba nie trzeba tu dawa� jaki�
 *	wodotrysk�w. Ewentualnie na koniec da si� jakie� 
 *	ludki lataj�ce w tle i strzelaj�ce
 *
 * * * * * * * * * * */
class Menu : public Scene
{
public:
	Menu();

private:
	void update();
	void render();

	void areYouSure(std::string comunicate);

private:
	enum {
		MainMenu,
		Start,
		Options,
		AreYouSure
	} actualState, previousState;

	sf::Font mainFont, infoFont;
	
	TextButton menuButtons[3];
	TextButton yesNoButtons[2];
	sf::Text logo, info, version, question;

	sf::SoundBuffer clickSound;
	sf::Sound click;

	bool answerFlag;
};

#endif // !Menu_h

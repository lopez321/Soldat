#ifndef Menu_h
#define Menu_h

#include <SFML\Audio.hpp>

#include "Scene.h"
#include "TextButton.h"
/* * * * * * * * * * *
 *
 *	Pierwszy i podstawowy widok gry. Nie bêdziemy siê 
 *	wysilaæ za bardzo i chyba nie trzeba tu dawaæ jakiœ
 *	wodotrysków. Ewentualnie na koniec da siê jakieœ 
 *	ludki lataj¹ce w tle i strzelaj¹ce
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

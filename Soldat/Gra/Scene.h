#ifndef Scene_h
#define Scene_h

#include "MainWindow.h"

/* * * * * * * * * * *
 *
 *	To jest g³ówna klasa dla wszystkich scen w grze.
 *	Po niej musz¹ dziedziczyc wszystkie kolejne
 *	(menu, opcje, pauzy etc.)
 *
 * * * * * * * * * * */
class Scene : public MainWindow
{
public:
	Scene() :
		main(this) { 
		if (music.getStatus() != sf::Music::Playing) {
			music.openFromFile("music/background.ogg");
			music.setLoop(true);
			music.play();
		}
	};
	// Ob³uga zdarzeñ, rednerowanie i wyœwietlenie sceny
	void run();

private:
	// Obs³uga zdarzeñ
	virtual void processEvent();
	// Zmiana ustawieñ
	virtual void update() = 0;
	// Rendeowanie i wyœwietlenie
	virtual void render() = 0;

protected:
	// Uchwyt do g³ownego wskaŸnika
	Scene *main;

};

#endif // !Scene_h

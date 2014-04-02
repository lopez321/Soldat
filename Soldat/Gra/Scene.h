#ifndef Scene_h
#define Scene_h

#include "MainWindow.h"

/* * * * * * * * * * *
 *
 *	To jest g��wna klasa dla wszystkich scen w grze.
 *	Po niej musz� dziedziczyc wszystkie kolejne
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
	// Ob�uga zdarze�, rednerowanie i wy�wietlenie sceny
	void run();

private:
	// Obs�uga zdarze�
	virtual void processEvent();
	// Zmiana ustawie�
	virtual void update() = 0;
	// Rendeowanie i wy�wietlenie
	virtual void render() = 0;

protected:
	// Uchwyt do g�ownego wska�nika
	Scene *main;

};

#endif // !Scene_h

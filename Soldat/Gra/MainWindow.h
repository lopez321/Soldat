#ifndef MainWindow_h
#define MainWindow_h

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

/* * * * * * * * * * *
 *
 *	Ta klasa jest tylko po to, ¿eby istnia³a jedna instancja
 *	okna i zmiennej do obs³ugi zdarzeñ, a kod innych
 *	klas by³ czytelniejszy. Po niej dziedziczy klasa Scene
 *	i ka¿da, która bêdzie wymagaæ bezpoœredniego dostêpu do 
 *	okna lub zdarzeñ. (poza scenami - one pobieraj¹ to z Scene)
 *
 * * * * * * * * * * * */
class MainWindow
{
protected:
	static sf::Event eventHandler;
	static sf::RenderWindow mainWindow;
	static sf::Music music;
};

#endif // !MainWindow_h

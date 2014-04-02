#ifndef MainWindow_h
#define MainWindow_h

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

/* * * * * * * * * * *
 *
 *	Ta klasa jest tylko po to, �eby istnia�a jedna instancja
 *	okna i zmiennej do obs�ugi zdarze�, a kod innych
 *	klas by� czytelniejszy. Po niej dziedziczy klasa Scene
 *	i ka�da, kt�ra b�dzie wymaga� bezpo�redniego dost�pu do 
 *	okna lub zdarze�. (poza scenami - one pobieraj� to z Scene)
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

#include "MainWindow.h"

// Handler do obs�ugi zdarze�
sf::Event MainWindow::eventHandler;
// Utworzenie podstawowego okna
sf::RenderWindow MainWindow::mainWindow(sf::VideoMode(1024, 600, 32),
	"Soldat (pre-alpha v.1)",
	sf::Style::Titlebar | sf::Style::Close);
// Podk�ad muzyczny
sf::Music MainWindow::music;
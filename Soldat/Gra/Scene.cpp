#include "Scene.h"

void Scene::run() {
	while (mainWindow.isOpen())
	{
		processEvent();
		update();
		render();
	}
}

void Scene::processEvent() {
	sf::Event event;
	while (mainWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			mainWindow.close();
	}
	eventHandler = event;
}
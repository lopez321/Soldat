#include "TextButton.h"

bool TextButton::isButtonClicked() {
	if (isButtonHover()
		&& eventHandler.type == sf::Event::MouseButtonReleased
		&& eventHandler.mouseButton.button == sf::Mouse::Left)
		return true;
	return false;
}

bool TextButton::isButtonHover() {
	sf::IntRect rect(this->getGlobalBounds());
	if (rect.contains(sf::Mouse::getPosition(mainWindow)))
		return true;
	return false;
}
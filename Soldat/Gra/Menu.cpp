#include "Menu.h"

Menu::Menu() : Scene() {
	// Stany scenyy
	previousState = MainMenu;
	actualState = MainMenu;
	answerFlag = false;

	// Czcionki
	mainFont.loadFromFile("fonts/carnevalee.ttf");
	infoFont.loadFromFile("fonts/arial.ttf");

	// Wektor pozycji
	sf::Vector2f position(mainWindow.getSize());
	position.x -= mainWindow.getSize().x / 3;
	position.y -= mainWindow.getSize().y / 3;
	// Stworzenie przycisków
	for (TextButton &option : menuButtons) {
		option.setCharacterSize(50);
		option.setColor(sf::Color::White);
		option.setFont(mainFont);
		option.setPosition(position);
		position.y += option.getCharacterSize();
	}
	menuButtons[0].setString("Start");
	menuButtons[1].setString("Options");
	menuButtons[2].setString("Quit");

	for (TextButton &button : yesNoButtons) {
		button.setCharacterSize(50);
		button.setFont(mainFont);
		button.setColor(sf::Color::White);
	}
	yesNoButtons[0].setString("Yes");
	yesNoButtons[1].setString("No");

	// Logo
	logo.setCharacterSize(100);
	logo.setColor(sf::Color::White);
	logo.setFont(mainFont);
	logo.setString("SOLDAT");
	position = (sf::Vector2f) mainWindow.getSize();
	position.x /= 2;
	position.x -= logo.getGlobalBounds().width / 2;
	position.y = 40;
	logo.setPosition(position);
	// Tekst z informacj¹
	info.setCharacterSize(10);
	info.setColor(sf::Color::White);
	info.setFont(infoFont);
	info.setString(L"Pawe³ Rozenkranc & Aleksander Stojanowski");
	position = (sf::Vector2f) mainWindow.getSize();
	position.x -= info.getGlobalBounds().width + 5;
	position.y -= info.getCharacterSize() + 5;
	info.setPosition(position);

	// Tekst z wersj¹
	version.setCharacterSize(10);
	version.setColor(sf::Color::White);
	version.setFont(infoFont);
	version.setString(L"v.1");
	position = (sf::Vector2f) mainWindow.getSize();
	position.x = 5;
	position.y -= version.getCharacterSize() + 5;
	version.setPosition(position);

	// DŸwiêk naciœniêcia przycisku
	clickSound.loadFromFile("sounds/click.wav");
	click.setBuffer(clickSound);
}

void Menu::update() {
	// Obs³uga aktualnego stanu ekranu
	switch (actualState)
	{
	case MainMenu:
		// Zmiana wygl¹du i dodanie dŸwiêku naciœniêcia do przycisków
		for (TextButton &button : menuButtons) {
			if (button.isButtonHover()) {
				button.setColor(sf::Color::Red);
				if (button.isButtonClicked())
					click.play();
			}
			else
				button.setColor(sf::Color::White);
		}

		// Przycisk zamkniêcia
		if (menuButtons[2].isButtonClicked()) {
			previousState = actualState;
			actualState = AreYouSure;
			areYouSure("Are you sure?");
		}
		break;
	case Start:

		break;
	case Options:

		break;
	case AreYouSure:
		// Zmiana wygl¹du i dodanie dŸwiêku naciœniêcia do przycisków
		for (TextButton &button : yesNoButtons) {
			if (button.isButtonHover()) {
				button.setColor(sf::Color::Red);
				if (button.isButtonClicked())
					click.play();
			}
			else
				button.setColor(sf::Color::White);
		}

		// Przycisk tak
		if (yesNoButtons[0].isButtonClicked()) {
			answerFlag = true;
		}
		// PRzycisk nie
		if (yesNoButtons[1].isButtonClicked()) {
			previousState = actualState;
			actualState = MainMenu;
		}
		break;
	default:
		actualState = MainMenu;
		break;
	}

	// Obs³uga odpowiedzi
	if (answerFlag) {
		answerFlag = false;
		switch (previousState)
		{
		case MainMenu:
			mainWindow.close();
			break;
		default:
			break;
		}
	}
}

void Menu::render() {
	mainWindow.clear();

	switch (actualState)
	{
	case MainMenu:
		for (TextButton &button : menuButtons)
			mainWindow.draw(button);
		break;
	case Start:

		break;
	case Options:

		break;
	case AreYouSure:
		mainWindow.draw(question);
		for (TextButton &button : yesNoButtons)
			mainWindow.draw(button);
		break;
	default:
		actualState = MainMenu;
		break;
	}

	mainWindow.draw(info);
	mainWindow.draw(version);
	mainWindow.draw(logo);

	mainWindow.display();
}

void Menu::areYouSure(std::string questionText) {
	question.setString(questionText);
	question.setFont(mainFont);
	question.setColor(sf::Color::White);
	question.setCharacterSize(50);
	sf::Vector2f position(mainWindow.getSize());
	position.x /= 2;
	position.y /= 2;
	position.x -= question.getGlobalBounds().width / 2;
	position.y -= question.getCharacterSize() / 2;
	question.setPosition(position);
	position.y += question.getCharacterSize();
	position.x = mainWindow.getSize().x / 2 - 10 - yesNoButtons[0].getGlobalBounds().width;
	yesNoButtons[0].setPosition(position);
	position.x = mainWindow.getSize().x / 2 + 10;
	yesNoButtons[1].setPosition(position);	
}
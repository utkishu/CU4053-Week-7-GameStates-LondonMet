#include "Pause.h"

Pause::Pause(sf::RenderWindow* hwnd, Input* in, GameState* gs)
{
	window = hwnd;
	input = in;
	gameState = gs;

	if (!font.loadFromFile("font/Fighting Spirit 2 bold.otf"))
	{
		std::cout << "Font did not load\n";
	}

	PauseText.setFont(font);
	PauseText.setCharacterSize(24);
	PauseText.setPosition(100, 100);
	//PauseText.setColor(sf::Color::Black);
	PauseText.setFillColor(sf::Color::Red);
	PauseText.setString("Press Escape to \n unPause the game");
}

Pause::~Pause()
{
}

void Pause::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		gameState->setCurrentState(State::LEVEL);
	}
}

void Pause::update(float dt)
{
}

void Pause::render()
{
	beginDraw();
	window->draw(PauseText);
	endDraw();
}

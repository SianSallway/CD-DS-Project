#include "SimonGameApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>

using namespace std;

SimonGameApp::SimonGameApp() {

}

SimonGameApp::~SimonGameApp() {

}

bool SimonGameApp::startup() {

	m_2dRenderer = new aie::Renderer2D();

	//automatically sets the game state to the main menu state when the program starts
	currentState = GameState::MenuState;
	isGameOver = false;

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	button = new Button("Play", 670, 350, 120, 50);

	return true;
}

void SimonGameApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete button;
}

void SimonGameApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	switch (currentState)
	{
	case GameState::MenuState:

		if (button->Update())
		{
			cout << "Button has been clicked" << endl;
			currentState = GameState::PlayState;
		}

		break;

	case GameState::PlayState:




		break;

	case GameState::GameOverState:

		break;

	case GameState::GameWinState:

		break;

	default:
		break;
	}


	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void SimonGameApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	//draws graphics and textures to the screen depending on the game state
	if (currentState == GameState::MenuState)
	{
		button->Draw(m_2dRenderer);
		m_2dRenderer->drawText(m_font, "Welcome to Simon", 550, 600);
		m_2dRenderer->drawText(m_font, "Developed by Sian Sallway", 923, 10);
	}
	else if (currentState == GameState::PlayState)
	{
		m_2dRenderer->drawText(m_font, "Memorise the pattern", 550, 600);
	}
	else if (currentState == GameState::GameOverState)
	{

	}
	else if (currentState == GameState::GameWinState)
	{
		 
	}

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 5, 10);

	// done drawing sprites
	m_2dRenderer->end();
}
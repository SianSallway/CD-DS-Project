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
	currentState = GameState::MenuState;
	isGameOver = false;

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	button = new Button("Play", 850, 500, 120, 50);

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

		cout << "This is the playing state\n";



		break;

	case GameState::GameOverState:

		break;

	default:
		break;
	}

	if (button->Update())
	{
		cout << "Button has been clicked" << endl;
		GameState::PlayState;
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

	// draw your stuff here!
	button->Draw(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Welcome to Simon", 700, 900);
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}
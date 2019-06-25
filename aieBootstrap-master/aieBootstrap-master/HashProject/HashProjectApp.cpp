#include "HashProjectApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

#define STANDALONEBUILD

HashProjectApp::HashProjectApp() {

}

HashProjectApp::~HashProjectApp() {

}

bool HashProjectApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
#ifdef STANDALONEBUILD
	m_font = new aie::Font("../../bin/font/consolas.ttf", 32);
	ship = new aie::Texture("../../../bin/textures/ship.png");
	ball = new aie::Texture("../../../bin/textures/ball.png");
#else
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	ship = new aie::Texture("textures/ship.png");
	ball = new aie::Texture("textures/ball.png");
#endif

	cout << "Press H key to add textures to hash table" << endl;
	cout << "\n";
	return true;
}

void HashProjectApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete ship;
}

void HashProjectApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	if (input->wasKeyPressed(aie::INPUT_KEY_H))
	{
		HashTable table(10);

		table["textures/ship.png"] = ship;
		cout << "Pointer: " << table["textures/ship.png"]<< endl;
		cout << "\n";

		table["textures/ball.png"] = ball;
		cout << "Pointer: "<< table["textures/ball.png"] << endl;
		cout << "\n";
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void HashProjectApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_2dRenderer->drawSprite(ship, 500, 500, 93, 80, 0, 0, 0, 0);
	m_2dRenderer->drawSprite(ball, 800, 500, 44, 44, 0, 0, 0, 0);
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	m_2dRenderer->drawText(m_font, "Press the H key to enter textures into a hash table", 200, 300);

	// done drawing sprites
	m_2dRenderer->end();
}
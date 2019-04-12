#include "ResourceManagmentApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>

using namespace std;

ResourceManagmentApp::ResourceManagmentApp() {

}

ResourceManagmentApp::~ResourceManagmentApp() {

}

bool ResourceManagmentApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	TexturePtr pShip = m_images.get("./textures/ship.png");
	//m_player = new Player(pShip);

	cout << "images loaded: " << m_images.getCount() << endl;
	return true;
}

void ResourceManagmentApp::shutdown() {

	cout << "images loaded: " << m_images.getCount() << endl;

	//delete m_player;

	m_images.collectGarbage();

	cout << "images loaded: " << m_images.getCount() << endl;

	delete m_font;
	delete m_2dRenderer;
}

void ResourceManagmentApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void ResourceManagmentApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}
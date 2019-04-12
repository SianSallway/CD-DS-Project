#include "HashingApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "imgui.h"

HashingApp::HashingApp() {

}

HashingApp::~HashingApp() {

}

bool HashingApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	hashImage = new aie::Texture("..\bin\textures\ship.png");

	return true;
}

void HashingApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void HashingApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	string userInput;
	static int value = 0;
	ImGui::InputInt("Value", &value);

	if (ImGui::Button("Calculate Hash", ImVec2(100, 0)))
	{
		//hashing.Hash(userInput);
	
	}


	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void HashingApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_2dRenderer->drawSprite(hashImage, 0, 0, 50, 50, 0, 0, 0, 0);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}
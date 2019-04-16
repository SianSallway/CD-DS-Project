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

	hashImage = new aie::Texture("..\bin\textures\ball.png");

	return true;
}

void HashingApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete hashImage;
}

void HashingApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	/*string userInput;
	static int value = 0;
	ImGui::InputInt("Value", &value);

	if (ImGui::Button("Calculate Hash", ImVec2(100, 0)))
	{
		//hashing.Hash(userInput);
	
	}*/


	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void HashingApp::draw() {

	char name[64];
	strcpy_s(name, 64, "Bob");
	int playerNumber = 1;
	int score = 100;
	char result[64];

	snprintf(result, 64, "Player %i (%s): %i points", playerNumber, name, score);

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	//m_2dRenderer->drawSprite(hashImage, 600, 400, 0, 0, 0, 0, 0, 0);

	//m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);
	//m_2dRenderer->drawSprite(hashImage, 200, 200, 100, 100);
	m_2dRenderer->drawText(m_font, result, 600, 400);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}
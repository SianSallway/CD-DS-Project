#include "DynamicArrayDemoApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "imgui.h"
#include <iostream>

using namespace std;

DynamicArrayDemoApp::DynamicArrayDemoApp() {

}

DynamicArrayDemoApp::~DynamicArrayDemoApp() {

}

bool DynamicArrayDemoApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	createArrayButton = new UIButton("Create Array", 200, 450, 190, 50);
	addBackButton = new UIButton("Add on end", 200, 390, 190, 50);
	removeEndButton = new UIButton("Remove end", 200, 290, 190, 50);

	return true;
}

void DynamicArrayDemoApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete addBackButton;
	delete removeEndButton;
	delete createArrayButton;
}

void DynamicArrayDemoApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	static int value = 0;
	ImGui::InputInt("Value", &value);

	if (createArrayButton->Update())
	{

	}
	if (addBackButton->Update())
	{
		cout << "Add To End Button has been clicked" << endl;
		array.AddToEnd(value);
	}
	if (removeEndButton->Update())
	{
		cout << "Remove End Button has been clicked" << endl;
		array.RemoveEnd();
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void DynamicArrayDemoApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_2dRenderer->drawText(m_font, "Dynamic Array Demo", 500, 650);
	addBackButton->Draw(m_2dRenderer);
	removeEndButton->Draw(m_2dRenderer);
	createArrayButton->Draw(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}
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
	removeEndButton = new UIButton("Remove end", 200, 330, 190, 50);
	addMiddleButton = new UIButton("Add to middle", 200, 270, 220, 50);
	removeMiddleButton = new UIButton("Remove from middle", 200, 210, 250, 50);

	return true;
}

void DynamicArrayDemoApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete addBackButton;
	delete removeEndButton;
	delete createArrayButton;
	delete removeMiddleButton;
	delete addMiddleButton;
}

void DynamicArrayDemoApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	static int value = 0;
	ImGui::InputInt("Value", &value);

	if (createArrayButton->Update())
	{
		currentAction = Action::Create;
	}
	if (addBackButton->Update())
	{
		currentAction = Action::AddToEnd;
		cout << "Add To End Button has been clicked" << endl;
		array.AddToEnd(value);
	}
	if (removeEndButton->Update())
	{
		currentAction = Action::RemoveEnd;
		cout << "Remove End Button has been clicked" << endl;
		array.RemoveEnd();
	}
	if (addMiddleButton->Update())
	{
		currentAction = Action::AddToMiddle;
		cout << "Add Middle Button has been clicked" << endl;
		
	}
	if (removeMiddleButton->Update())
	{
		currentAction = Action::RemoveFromMiddle;
		cout << "Remove Middle Button has been clicked" << endl;
		
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
	m_2dRenderer->drawText(m_font, "Developed by Sian Sallway", 895, 10);
	addBackButton->Draw(m_2dRenderer);
	removeEndButton->Draw(m_2dRenderer);
	createArrayButton->Draw(m_2dRenderer);
	removeMiddleButton->Draw(m_2dRenderer);
	addMiddleButton->Draw(m_2dRenderer);

	if (currentAction == Action::Create)
	{
		m_2dRenderer->drawText(m_font, "Your array has been created!", 600, 400);
	}
	if (currentAction == Action::AddToEnd)
	{
		m_2dRenderer->drawText(m_font, "You've added a value to the end ", 600, 400);
		m_2dRenderer->drawText(m_font, "of the array", 600, 350);
	}
	if (currentAction == Action::RemoveEnd)
	{
		m_2dRenderer->drawText(m_font, "You've removed a value from the end ", 600, 400);
		m_2dRenderer->drawText(m_font, "of the array", 600, 350);
	}
	if (currentAction == Action::AddToMiddle)
	{
		m_2dRenderer->drawText(m_font, "You've added a value to the middle ", 600, 400);
		m_2dRenderer->drawText(m_font, "of the array", 600, 350);
	}
	if (currentAction == Action::RemoveFromMiddle)
	{
		m_2dRenderer->drawText(m_font, "You've removed a value from the middle ", 600, 400);
		m_2dRenderer->drawText(m_font, "of the array", 600, 350);
	}

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}
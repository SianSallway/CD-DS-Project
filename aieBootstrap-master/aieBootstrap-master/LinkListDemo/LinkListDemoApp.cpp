#include "LinkListDemoApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "imgui.h"
#include <iostream>

using namespace std;

LinkListDemoApp::LinkListDemoApp() {

}

LinkListDemoApp::~LinkListDemoApp() {

}

bool LinkListDemoApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	pushFrontButton = new ScreenButton("Add to front", 300, 400, 190, 50);
	pushBackButton = new ScreenButton("Add to back", 300, 340, 190, 50);
	popFrontButton = new ScreenButton("Remove from front", 300, 230, 235, 50);
	popBackButton = new ScreenButton("Remove from back", 300, 170, 235, 50);

	return true;
}

void LinkListDemoApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete pushBackButton;
	delete pushFrontButton;
	delete popBackButton;
	delete popFrontButton;
}

void LinkListDemoApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	static int value = 0;
	ImGui::InputInt("Value", &value);

	if (pushBackButton->Update())
	{
		cout << "Push to back Button has been clicked" << endl;
		userList.PushBack(value);
	}
	if (pushFrontButton->Update())
	{
		cout << "Push to front Button has been clicked" << endl;
		userList.PushFront(value);
	}
	if (popFrontButton->Update())
	{
		cout << "Remove from front Button has been clicked" << endl;
		userList.PopFront();
	}
	if (popBackButton->Update())
	{
		cout << "Remove from back Button has been clicked" << endl;
		userList.PopBack();
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void LinkListDemoApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_2dRenderer->drawText(m_font, "Link List Demo", 500, 600);
	m_2dRenderer->drawText(m_font, "Developed by Sian Sallway", 895, 10);
	pushBackButton->Draw(m_2dRenderer);
	pushFrontButton->Draw(m_2dRenderer);
	popBackButton->Draw(m_2dRenderer);
	popFrontButton->Draw(m_2dRenderer);
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 10, 10);

	// done drawing sprites
	m_2dRenderer->end();
}
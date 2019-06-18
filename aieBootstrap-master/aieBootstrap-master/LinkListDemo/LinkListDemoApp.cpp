#include "LinkListDemoApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "imgui.h"
#include <iostream>

using namespace std;

//#define STANDALONEBUILD

LinkListDemoApp::LinkListDemoApp() {

}

LinkListDemoApp::~LinkListDemoApp() {

}

bool LinkListDemoApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
#ifdef STANDALONEBUILD
	m_font = new aie::Font("../../../../bin/font/consolas.ttf", 32);
#else
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
#endif
	pushFrontButton = new ScreenButton("Add to front", 200, 450, 190, 50);
	pushBackButton = new ScreenButton("Add to back", 200, 390, 190, 50);
	popFrontButton = new ScreenButton("Remove from front", 200, 290, 235, 50);
	popBackButton = new ScreenButton("Remove from back", 200, 230, 235, 50);
	clearListButton = new ScreenButton("Clear List", 175, 110, 190, 50);
	removeButton = new ScreenButton("Remove Element", 181, 170, 200, 50);
	countButton = new ScreenButton("Total Elements", 950, 570, 250, 50);

	return true;
}

void LinkListDemoApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete pushBackButton;
	delete pushFrontButton;
	delete popBackButton;
	delete popFrontButton;
	delete clearListButton;
	delete removeButton;
	delete countButton;
}

void LinkListDemoApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	static int value = 0;
	ImGui::InputInt("Value", &value);

	if (pushBackButton->Update()|| input->wasKeyPressed(aie::INPUT_KEY_A))
	{
		currentAction = Action::PushBack;
		cout << "Push to back Button has been clicked" << endl;
		userList.PushBack(value);
	}
	if (pushFrontButton->Update() || input->wasKeyPressed(aie::INPUT_KEY_D))
	{
		currentAction = Action::PushFront;
		cout << "Push to front Button has been clicked" << endl;
		userList.PushFront(value);
	}
	if (popFrontButton->Update() || input->wasKeyPressed(aie::INPUT_KEY_T))
	{
		currentAction = Action::PopFront;
		cout << "Remove from front Button has been clicked" << endl;
		userList.PopFront();

	}
	if (popBackButton->Update() || input->wasKeyPressed(aie::INPUT_KEY_S))
	{
		currentAction = Action::PopBack;
		cout << "Remove from back Button has been clicked" << endl;
		userList.PopBack();
	}
	if (clearListButton->Update() || input->wasKeyPressed(aie::INPUT_KEY_C))
	{
		currentAction = Action::Clearing;
		cout << "Clear List Button has been clicked" << endl;
		userList.ClearList();
	}
	if (removeButton->Update() || input->wasKeyPressed(aie::INPUT_KEY_R))
	{
		currentAction = Action::Removing;
		cout << "Remove Button has been clicked" << endl;
		userList.Remove(value);
	}
	if (countButton->Update() || input->wasKeyPressed(aie::INPUT_KEY_G))
	{
		currentAction = Action::Counting;
		cout << "Count Button has been clicked" << endl;
		userList.Count();
	}
	if (input->isKeyDown(aie::INPUT_KEY_P))
	{
		currentAction = Action::Printing;
		userList.PrintList();
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
	m_2dRenderer->drawText(m_font, "Link List Demo", 500, 650);
	m_2dRenderer->drawText(m_font, "For adding to list", 50, 500);
	m_2dRenderer->drawText(m_font, "For removing from list", 50, 330);
	m_2dRenderer->drawText(m_font, "Developed by Sian Sallway", 895, 10);
	/*pushBackButton->Draw(m_2dRenderer);
	pushFrontButton->Draw(m_2dRenderer);
	popBackButton->Draw(m_2dRenderer);
	popFrontButton->Draw(m_2dRenderer);
	clearListButton->Draw(m_2dRenderer);
	removeButton->Draw(m_2dRenderer);
	countButton->Draw(m_2dRenderer);*/

	if (currentAction == Action::PushBack)
	{
		m_2dRenderer->drawText(m_font, "You've added an element ", 600, 400);
		m_2dRenderer->drawText(m_font, "to the back of your list", 600, 350);
	}
	if (currentAction == Action::PushFront)
	{
		m_2dRenderer->drawText(m_font, "You've added an element ", 600, 400);
		m_2dRenderer->drawText(m_font, "to the front of your list", 600, 350);
	}
	if (currentAction == Action::PopFront)
	{
		m_2dRenderer->drawText(m_font, "You've removed the first element ", 600, 400);
		m_2dRenderer->drawText(m_font, "from your list", 600, 350);
	}
	if (currentAction == Action::PopBack)
	{
		m_2dRenderer->drawText(m_font, "You've removed the last element ", 600, 400);
		m_2dRenderer->drawText(m_font, "from your list", 600, 350);
	}
	if (currentAction == Action::Clearing)
	{
		m_2dRenderer->drawText(m_font, "You've removed all elements ", 600, 400);
		m_2dRenderer->drawText(m_font, "from your list", 600, 350);
	}
	if (currentAction == Action::Removing)
	{
		m_2dRenderer->drawText(m_font, "You've removed all elements matching ", 600, 400);
		m_2dRenderer->drawText(m_font, "your chosen value from your list", 600, 350);
	}
	if (currentAction == Action::Counting)
	{
		m_2dRenderer->drawText(m_font, "The total amount of elements in ", 600, 400);
		m_2dRenderer->drawText(m_font, "your list can be seen in the console window ", 500, 350);
	}

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 10, 10);

	// done drawing sprites
	m_2dRenderer->end();
}
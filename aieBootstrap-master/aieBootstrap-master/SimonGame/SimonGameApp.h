#pragma once
#include <list>
#include <iostream>
#include "Application.h"
#include "Renderer2D.h"
#include "Button.h"
#include "ProgressBar.h"
#include "LinkList.h"
#include "ListNode.h"

using namespace std;

enum class GameState
{
	MenuState,
	InstructState,
	PlayState,
	GameOverState,
	GameWinState
};

enum Colour
{
	Red,
	Blue,
	Yellow,
	Green
};

class SimonGameApp : public aie::Application {
public:

	SimonGameApp();
	virtual ~SimonGameApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	float barValue = 0.f;
	float timeElapsed = 0.f;
	float timeDelay = 5.f;

protected:

	bool isGameOver;
	bool playerHasWon;


	aie::Renderer2D* m_2dRenderer;
	aie::Font* m_font;

	Button* playButton;
	Button* retryButton;
	Button* instructionButton;
	Button* backButton;
	Button* redGameButton;
	Button* blueGameButton;
	Button* yellowGameButton;
	Button* greenGameButton;

	ProgressBar* progBar;

private:

	GameState currentState;
	Colour colourState;
	LinkList playerPatternList;
	LinkList followPattern;
	ListNode* listNode;
	ListNode* currentPos;
	ListNode* displayColour;
};
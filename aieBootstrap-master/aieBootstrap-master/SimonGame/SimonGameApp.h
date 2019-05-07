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
	FollowState,
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

	bool CompareList(ListNode* pNode, ListNode* fNode);

	float barValue = 0.f;
	float timeElapsed = 0.f;
	float timeDelay = 1.f;
	int listCount = 0;

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
	Colour currentColour;
	int colourGuessed;
	LinkList playerPatternList;
	LinkList followPattern;
	ListNode* playerNode;
	ListNode* followNode;
	ListNode* currentPos = nullptr;
	int displayColour;
};
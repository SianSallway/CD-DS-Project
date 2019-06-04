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

enum class GameState //stores an integer value for each state of the game
{
	MenuState,
	InstructState,
	FollowState,
	PlayState,
	GameOverState,
	GameWinState
};

enum Colour //stores an integer value for each state of the FollowState button colours
{
	Red,
	Blue,
	Yellow,
	Green
};

//handles the drawing and execution of the main game and addition class properties 
class SimonGameApp : public aie::Application {
public:

	SimonGameApp();
	virtual ~SimonGameApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	//passes in two ListNode pointers to loop through both lists and compare each element value
	//depending on the outcome, either the GameOverState or the GameWinState is triggered
	bool CompareList(ListNode* pNode, ListNode* fNode);

	float barValue = 0.f;		//stores the starting value of the players progress bar
	float timeElapsed = 0.f;	//stores the amount of time passed in the program
	float timeDelay = 1.f;		//stores a float that will allow for a game element to be displayed for a certain amount of time
	int listCount = 0;			//stores the amount of values the player has pushed to their list

protected:

	bool isGameOver;			//returns true is the game has ended but the player has not won
	bool playerHasWon;			//return true if game has ended and the player has won

	aie::Renderer2D* m_2dRenderer;
	aie::Font* m_font;

	Button* playButton;				//Button object, triggers the start of the game when pressed
	Button* retryButton;			//Button object, restarts the game when pressed
	Button* instructionButton;		//Button object, triggers the InstructState when pressed
	Button* backButton;				//Button object, triggers the assigned state when pressed
	Button* redGameButton;			//Button object, pushes the Red Colour state value to the players list when pressed
	Button* blueGameButton;			//Button object, pushes the Blue Colour state value to the players list when pressed
	Button* yellowGameButton;		//Button object, pushes the Yellow Colour state value to the players list when pressed
	Button* greenGameButton;		//Button object, pushes the Green Colour state value to the players list when pressed

	ProgressBar* progBar;			//ProgressBar object, value increases with each accurate guess

private:

	GameState currentState;			//stores the value of the current game state
	Colour currentColour;			//stores the value of the current colour state
	int colourGuessed;				//stores the value of the button pressed
	LinkList playerPatternList;		//stores the list the player will be pushing values to when the game buttons are pressed
	LinkList followPattern;			//stores the list the pattern is stored in, this list will be compared to the players list 
	ListNode* playerNode;			//pointer passed into the CompareList function to loop through the elements of the players list
	ListNode* followNode;			//pointer passed into the CompareList function to loop through the elements of the games list
	ListNode* currentPos = nullptr;	//stores the current positon in the list as we loop through it
	int displayColour;				//stores the value of the colour being displayed on the game buttons
};
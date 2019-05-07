#include "SimonGameApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>

using namespace std;

SimonGameApp::SimonGameApp() {

}

SimonGameApp::~SimonGameApp() {

}

bool SimonGameApp::startup() {

	m_2dRenderer = new aie::Renderer2D();

	//automatically sets the game state to the main menu state when the program starts
	currentState = GameState::MenuState;
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	playButton = new Button("Play", 670, 350, 120, 50);
	retryButton = new Button("Play again", 670, 350, 200, 50);
	instructionButton = new Button("Instructions", 670, 250, 250, 50);
	backButton = new Button("Back", 630, 120, 120, 50);
	redGameButton = new Button(" ", 850, 350, 150, 150);
	blueGameButton = new Button(" ", 1002, 350, 150, 150);
	yellowGameButton = new Button(" ", 850, 198, 150, 150);
	greenGameButton = new Button(" ", 1002, 198, 150, 150);
	progBar = new ProgressBar(920, 500, 300, 20);

	//Pushes colour onto the end of list, creating the pattern that the player will have to try and memorise 
	followPattern.PushBack(Red);
	followPattern.PushBack(Blue);
	followPattern.PushBack(Yellow);
	followPattern.PushBack(Green);
	followPattern.PushBack(Yellow);
	followPattern.PushBack(Green);
	followPattern.PushBack(Red);
	followPattern.PushBack(Blue);
	followPattern.PushBack(Red);
	followPattern.PushBack(Yellow);
	followPattern.PushBack(Red);
	followPattern.PushBack(Blue);
	followPattern.PushBack(Yellow);
	followPattern.PushBack(Green);
	followPattern.PushBack(Yellow);
	followPattern.PushBack(Blue);

	// current position will start has the first node in the list 
	currentPos = followPattern.First();

	//cout << "FOO " << currentPos->GetNext() << endl;

	return true;
}

void SimonGameApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete playButton;
	delete retryButton;
	delete instructionButton;
	delete backButton;
	delete progBar;
	delete redGameButton;
	delete blueGameButton;
	delete yellowGameButton;
	delete greenGameButton;

}

bool SimonGameApp::CompareList(ListNode* pNode, ListNode* fNode)
{
	pNode = playerPatternList.First();
	fNode = followPattern.First();

	if (pNode->GetValue() != fNode->GetValue())
	{
		cout << "Both lists are either empty OR not identical" << endl;
		currentState = GameState::GameOverState;
		barValue = 0.f;
	}
	else 
	{
		barValue += 1.f;
		progBar->SetValue(barValue);
		
		pNode = pNode->GetNext();
		fNode = fNode->GetNext();

		if (pNode->GetValue() == fNode->GetValue())
		{
			cout << "identical!!!" << endl;
			currentState = GameState::GameWinState;
			return true;
		}
	}
}

void SimonGameApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	timeElapsed += deltaTime;

	switch (currentState)
	{
	case GameState::MenuState:

		//performs task based on player input, in this case if the play button has been clicked
		if (playButton->Update())
		{
			cout << "Play Button has been clicked" << endl;
			currentState = GameState::FollowState;
		}

		if (instructionButton->Update())
		{
			cout << "Instruction Button has been clicked" << endl;
			currentState = GameState::InstructState;
		}
		break;

	case GameState::InstructState:

		if (backButton->Update())
		{
			cout << "Back Button has been clicked" << endl;
			currentState = GameState::MenuState;
		}
		break;

	case GameState::FollowState:

		if (currentPos == nullptr)
			break;

		if (timeElapsed > timeDelay)
		{
			currentPos = currentPos->GetNext();
			cout << "Current position in this list is: " << currentPos << endl;

			timeElapsed = 0.f;
		}
		if (currentPos == followPattern.Last())
		{
			currentState = GameState::PlayState;
		}
		break;

	case GameState::PlayState:

		//performs task based on player input, in this case if the red button has been clicked
		if (redGameButton->Update())
		{
			cout << "Red Button has been clicked" << endl;
			playerPatternList.PushBack(Red); // using 0
			listCount += 1;
		}
		//performs task based on player input, in this case if the blue button has been clicked
		if (blueGameButton->Update())
		{
			cout << "Blue Button has been clicked" << endl;
			playerPatternList.PushBack(Blue);
			listCount += 1;
		}
		//performs task based on player input, in this case if the yellow button has been clicked
		if (yellowGameButton->Update())
		{
			cout << "Yellow Button has been clicked" << endl;
			playerPatternList.PushBack(Yellow);
			listCount += 1;
		}
		//performs task based on player input, in this case if the green button has been clicked
		if (greenGameButton->Update())
		{
			cout << "Green Button has been clicked" << endl;
			playerPatternList.PushBack(Green);
			listCount += 1;
		}

		if (listCount == 15)
		{
			CompareList(playerNode, followNode);
		}
		break;

	case GameState::GameOverState:

		if (retryButton->Update())
		{
			listCount = 0;
			cout << "Replay Button has been clicked" << endl;
			// current position will start has the first node in the list 
			currentPos = followPattern.First();
			currentState = GameState::FollowState;
		}
		break;

	case GameState::GameWinState:

		if (retryButton->Update())
		{
			listCount = 0;
			cout << "Replay Button has been clicked" << endl;
			// current position will start has the first node in the list 
			currentPos = followPattern.First();
			currentState = GameState::FollowState;
		}
		break;
	default:
		break;
	}
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void SimonGameApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	//draws graphics and textures to the screen depending on the game state
	if (currentState == GameState::MenuState) //default state on startup, can be triggered if the back button on the instructions menu is pressed
	{
		playButton->Draw(m_2dRenderer);												//Draws the play button to the Main Menu screen  
		instructionButton->Draw(m_2dRenderer);										//Draws the instructions button to the Main Menu screen that will take you to the Instructions menu 
		m_2dRenderer->drawText(m_font, "Welcome to Simon", 550, 600);				//Draws stand-alone text that is only meant for display purposes
		m_2dRenderer->drawText(m_font, "Developed by Sian Sallway", 830, 10);		//Draws stand-alone text that is only meant for display purposes
	}
	else if (currentState == GameState::InstructState) //Is triggered when the instructions button is pressed
	{
		backButton->Draw(m_2dRenderer);												//Draws the back button to the Instructions Menu screen that will take you to the Main Menu 
		m_2dRenderer->drawText(m_font, "How to Play", 550, 680);					//Draws stand-alone text that is only meant for display purposes
		m_2dRenderer->drawText(m_font, "The pattern will appear to you on your left, ", 300, 550);	//Draws stand-alone text that is only meant for display purposes
		m_2dRenderer->drawText(m_font, "once the sequence is done press the buttons on your right ", 150, 450);	//Draws stand-alone text that is only meant for display purposes
		m_2dRenderer->drawText(m_font, "and see how much you remember!", 400, 400);	//Draws stand-alone text that is only meant for display purposes
		m_2dRenderer->drawText(m_font, "Your progress bar will tell you how you're doing as you recite it", 100, 250);	//Draws stand-alone text that is only meant for display purposes
		m_2dRenderer->drawText(m_font, "Good Luck!", 550, 180);						//Draws stand-alone text that is only meant for display purposes
	}
	else if (currentState == GameState::FollowState)
	{
		m_2dRenderer->drawText(m_font, "Watch the pattern", 550, 600);			//Draws stand-alone text that is only meant for display purposes
		redGameButton->DrawRedGameButton(m_2dRenderer);								//Draws a square red button to the screen that will be used as part of the game play					
		blueGameButton->DrawBlueGameButton(m_2dRenderer);							//Draws a square blue button to the screen that will be used as part of the game play
		yellowGameButton->DrawYellowGameButton(m_2dRenderer);						//Draws a square yellow button to the screen that will be used as part of the game play
		greenGameButton->DrawGreenGameButton(m_2dRenderer);							//Draws a square green button to the screen that will be used as part of the game play
		m_2dRenderer->drawBox(280, 350, 150, 150, 0, 0);//red(L)
		m_2dRenderer->drawBox(433, 350, 150, 150, 0, 0); //blue(R)
		m_2dRenderer->drawBox(280, 198, 150, 150, 0, 0);//yellow(L)
		m_2dRenderer->drawBox(433, 198, 150, 150, 0, 0); //green(R)

		if (currentPos != nullptr)
		{
			displayColour = currentPos->GetValue();

			if (displayColour == Red)
			{
				m_2dRenderer->setRenderColour(1, 0, 0, 1);
				m_2dRenderer->drawBox(280, 350, 150, 150, 0, 0);
				//currentColour = Red;
			}
			else if (displayColour == Blue)
			{
				m_2dRenderer->setRenderColour(0, 0, 1, 1);
				m_2dRenderer->drawBox(433, 350, 150, 150, 0, 0);
				//currentColour = Blue;
			}
			else if (displayColour == Yellow)
			{
				m_2dRenderer->setRenderColour(1, 1, 0, 1);
				m_2dRenderer->drawBox(280, 198, 150, 150, 0, 0);
				//currentColour = Yellow;
			}
			else if (displayColour == Green)
			{
				m_2dRenderer->setRenderColour(0, 1, 0, 1);
				m_2dRenderer->drawBox(433, 198, 150, 150, 0, 0);
				//currentColour = Green;
			}
		}
	}
	else if (currentState == GameState::PlayState) //Is triggered when the play button on the main menu is pressed OR if the retry button on the game over screen and game win scene is pressed
	{
		m_2dRenderer->drawText(m_font, "Memorise the pattern", 550, 600);			//Draws stand-alone text that is only meant for display purposes
		m_2dRenderer->drawText(m_font, "Progress", 600, 490);						//Draws stand-alone text that is only meant for display purposes
		progBar->Draw(m_2dRenderer);												//Draws a progress bar background that will become concealed as other buttons are pressed in the play state
		progBar->SetValue(barValue);												//Draws a progress bar that will increase in size as other buttons are pressed and automatically sets it to being 'empty'
		redGameButton->DrawRedGameButton(m_2dRenderer);								//Draws a square red button to the screen that will be used as part of the game play					
		blueGameButton->DrawBlueGameButton(m_2dRenderer);							//Draws a square blue button to the screen that will be used as part of the game play
		yellowGameButton->DrawYellowGameButton(m_2dRenderer);						//Draws a square yellow button to the screen that will be used as part of the game play
		greenGameButton->DrawGreenGameButton(m_2dRenderer);							//Draws a square green button to the screen that will be used as part of the game play
		m_2dRenderer->drawBox(280, 350, 150, 150, 0, 0);//red(L)
		m_2dRenderer->drawBox(433, 350, 150, 150, 0, 0); //blue(R)
		m_2dRenderer->drawBox(280, 198, 150, 150, 0, 0);//yellow(L)
		m_2dRenderer->drawBox(433, 198, 150, 150, 0, 0); //green(R)
	}
	else if (currentState == GameState::GameOverState) //Is triggered when/if the player loses the game
	{
		m_2dRenderer->drawText(m_font, "Game Over :(", 550, 600);					//Draws stand-alone text that is only meant for display purposes and lets the player know that they've lost
		retryButton->Draw(m_2dRenderer);											//Draws the retry button to the screen that will trigger the play state when pressed, restarting the game

	}
	else if (currentState == GameState::GameWinState) //Is triggered when/if the player wins the game
	{
		m_2dRenderer->drawText(m_font, "You Won!!!", 550, 600);						//Draws stand-alone text that is only meant for display purposes and lets the player know that they've won
		retryButton->Draw(m_2dRenderer);											//Draws the retry button to the screen that will trigger the play state when pressed, restarting the game
	}

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 5, 10);

	// done drawing sprites
	m_2dRenderer->end();
}
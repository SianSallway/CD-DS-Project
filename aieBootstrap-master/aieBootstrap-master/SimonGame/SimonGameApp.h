#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Button.h"
#include "ProgressBar.h"

enum class GameState
{
	MenuState,
	PlayState,
	GameOverState,
	GameWinState
};

class SimonGameApp : public aie::Application {
public:

	SimonGameApp();
	virtual ~SimonGameApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	bool isGameOver;
	bool playerHasWon;

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	
	Button* playButton;
	Button* retryButton;
	Button* redGameButton;
	Button* blueGameButton;
	Button* yellowGameButton;
	Button* greenGameButton;

	ProgressBar* progBar;

private:

	GameState currentState;

};
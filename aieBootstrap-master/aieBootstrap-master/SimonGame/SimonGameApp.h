#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Button.h"

enum class GameState
{
	MenuState,
	PlayState,
	GameOverState
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

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	
	Button* button;

private:

	GameState currentState;

};
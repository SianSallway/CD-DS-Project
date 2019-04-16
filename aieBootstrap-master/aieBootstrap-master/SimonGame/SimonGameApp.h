#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Button.h"

class SimonGameApp : public aie::Application {
public:

	SimonGameApp();
	virtual ~SimonGameApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	
	Button* button;
};
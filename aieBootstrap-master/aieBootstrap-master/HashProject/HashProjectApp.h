#pragma once

#include "Application.h"
#include "Renderer2D.h"

class HashProjectApp : public aie::Application {
public:

	HashProjectApp();
	virtual ~HashProjectApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Texture*		ship;

};
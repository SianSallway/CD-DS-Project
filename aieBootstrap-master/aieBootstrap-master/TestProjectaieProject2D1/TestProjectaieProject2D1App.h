#pragma once

#include "Application.h"
#include "Renderer2D.h"

class TestProjectaieProject2D1App : public aie::Application {
public:

	TestProjectaieProject2D1App();
	virtual ~TestProjectaieProject2D1App();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};
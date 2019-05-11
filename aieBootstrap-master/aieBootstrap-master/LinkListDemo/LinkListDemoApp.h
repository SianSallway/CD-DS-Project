#pragma once
#include "ScreenButton.h"
#include "List.h"
#include "Node.h"
#include "Application.h"
#include "Renderer2D.h"

class LinkListDemoApp : public aie::Application {
public:

	LinkListDemoApp();
	virtual ~LinkListDemoApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	int userInput;

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	List userList;
	ScreenButton* pushBackButton;
	ScreenButton* pushFrontButton;
	ScreenButton* popFrontButton;
	ScreenButton* popBackButton;

};
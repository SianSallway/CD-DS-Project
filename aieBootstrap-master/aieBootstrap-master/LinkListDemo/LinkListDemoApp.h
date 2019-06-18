#pragma once
#include "ScreenButton.h"
#include "List.h"
#include "Node.h"
#include "Application.h"
#include "Renderer2D.h"

enum class Action
{
	PushBack,
	PushFront,
	PopBack,
	PopFront,
	Removing,
	Counting,
	Clearing, 
	Printing
};

class LinkListDemoApp : public aie::Application {
public:

	LinkListDemoApp();
	virtual ~LinkListDemoApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	List userList;
	Action currentAction;
	ScreenButton* pushBackButton;
	ScreenButton* pushFrontButton;
	ScreenButton* popFrontButton;
	ScreenButton* popBackButton;
	ScreenButton* clearListButton;
	ScreenButton* removeButton;
	ScreenButton* countButton;

};
#pragma once
#include "DynamicArray.h"
#include "UIButton.h"
#include "Application.h"
#include "Renderer2D.h"

enum class Action
{
	Create,
	AddToEnd,
	RemoveEnd,
	AddToMiddle,
	RemoveFromPos,
	DeleteArray
};

class DynamicArrayDemoApp : public aie::Application {
public:

	DynamicArrayDemoApp();
	virtual ~DynamicArrayDemoApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	DynamicArray array;
	Action currentAction;
	UIButton* addBackButton;
	UIButton* removeEndButton;
	UIButton* createArrayButton;
	UIButton* removePosButton;
	UIButton* addMiddleButton;
	UIButton* deleteButton;
};
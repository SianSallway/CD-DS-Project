#pragma once
#include "HashFunction.h"
#include "Application.h"
#include "Renderer2D.h"

class HashingApp : public aie::Application {
public:

	HashingApp();
	virtual ~HashingApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	HashFunction hashing;

	aie::Texture* hashImage;

};
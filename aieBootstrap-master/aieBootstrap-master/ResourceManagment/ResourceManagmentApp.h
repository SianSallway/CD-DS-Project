#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include"Player.h"
#include "ResourceManager.h"

class ResourceManagmentApp : public aie::Application {
public:

	ResourceManagmentApp();
	virtual ~ResourceManagmentApp();

	virtual bool startup();

	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	ResourceManager<aie::Texture> m_images;
	Player* m_player;
};
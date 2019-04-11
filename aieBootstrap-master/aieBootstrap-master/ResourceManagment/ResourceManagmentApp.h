#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include"Player.h"
#include "ResourceManager.h"
#include <memory>

using namespace std;
//updated

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
	ResourceManager<aie::Font, int> m_fonts;

	shared_ptr<aie::Font> font = m_fonts.get("./font/consolas.ttf", 32);
	shared_ptr<aie::Texture> grass = m_images.get(".texture/grass.png");
	//Player* m_player;
};
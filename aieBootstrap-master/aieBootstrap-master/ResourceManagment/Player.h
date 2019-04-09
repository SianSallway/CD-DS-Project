#pragma once
#include <string>
#include "Resource.h"
#include "Application.h"
#include "Renderer2D.h"

using namespace std;

typedef shared_ptr<Resource<aie::Texture>> TexturePtr;

class Player
{
public:

	Player(TexturePtr texture) : m_ship(texture) {};
	~Player();

private:

	TexturePtr m_ship;
};


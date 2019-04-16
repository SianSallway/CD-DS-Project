#include "AnimatedSprite.h"
#include <Renderer2D.h>
#include "assert.h"
#include <iostream>

using namespace std;

AnimatedSprite::AnimatedSprite() : m_currentFrame(0), m_timer(0)
{	
}


AnimatedSprite::~AnimatedSprite()
{
	for (Frame f : m_frames) {
		delete f.m_texture;
	}
}

int AnimatedSprite::addFrame(aie::Texture* texture, float delay)
{
	if (texture == nullptr)
	{
		return ERROR_NULL_TEXTURE;
	}
	
	if (texture->getPixels() == nullptr)
	{
		return ERROR_NO_PIXEL_DATA;
	}
	
	m_frames.push_back(Frame(texture, delay));

	return NO_ERROR;
}

void AnimatedSprite::update(float deltaTime)
{
	m_timer += deltaTime;

	if (m_timer >= m_frames.at(m_currentFrame).m_delay) {
		m_timer -= m_frames.at(m_currentFrame).m_delay;
		m_currentFrame++;
		if (m_currentFrame >= m_frames.size())
			m_currentFrame = 0;
	}
}

void AnimatedSprite::draw(aie::Renderer2D* renderer, int x, int y, int flags)
{
	Frame frame = m_frames.at(m_currentFrame);

	switch (flags)
	{
	case 0:
		
		renderer->drawSprite(frame.m_texture, x, y);
		
		break;

	case DRAW_FLIP_X:

		renderer->setUVRect(0.0f, 0.0f, -1.0f, 1.0f);
		renderer->drawSprite(frame.m_texture, x, y);
		renderer->setUVRect(0.0f, 0.0f, 1.0f, 1.0f);

		break;

	case DRAW_FLIP_Y:

		renderer->setUVRect(0.0f, 0.0f, 1.0f, -1.0f);
		renderer->drawSprite(frame.m_texture, x, y);
		renderer->setUVRect(0.0f, 0.0f, 1.0f, 1.0f);

		break;

	case DRAW_FLIP_X | DRAW_FLIP_Y:

		renderer->setUVRect(0.0f, 0.0f, -1.0f, -1.0f);
		renderer->drawSprite(frame.m_texture, x, y);
		renderer->setUVRect(0.0f, 0.0f, 1.0f, 1.0f);

		break;

	default:

		throw exception((string("Invalid flag value: ") + to_string(flags)).c_str());

		break;
	}

}
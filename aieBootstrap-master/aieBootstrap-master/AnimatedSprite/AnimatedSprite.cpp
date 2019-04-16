#include "AnimatedSprite.h"
#include <Renderer2D.h>


AnimatedSprite::AnimatedSprite() : m_currentFrame(0), m_timer(0)
{	
}


AnimatedSprite::~AnimatedSprite()
{
	for (Frame f : m_frames) {
		delete f.m_texture;
	}
}

void AnimatedSprite::addFrame(aie::Texture* texture, float delay)
{
	m_frames.push_back(Frame(texture, delay));
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

void AnimatedSprite::draw(aie::Renderer2D* renderer, int x, int y)
{
	Frame frame = m_frames.at(m_currentFrame);
	renderer->drawSprite(frame.m_texture, x, y);
}
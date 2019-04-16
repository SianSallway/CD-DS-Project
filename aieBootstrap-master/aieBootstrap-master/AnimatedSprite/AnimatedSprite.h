#pragma once
#include <vector>
#include <Texture.h>

const int DRAW_FLIP_X = 0x01;
const int DRAW_FLIP_Y = 0x04;
const int NO_ERROR = 0;
const int ERROR_NULL_TEXTURE = -1;
const int ERROR_NO_PIXEL_DATA = -2;

namespace aie {
	class Renderer2D;
};

class AnimatedSprite
{
private:
	struct Frame {
		aie::Texture* m_texture;
		float m_delay;
		Frame(aie::Texture* texture, float delay) : m_texture(texture), m_delay(delay) {}
	};

public:
	AnimatedSprite();
	~AnimatedSprite();

	int addFrame(aie::Texture* texture, float delay);

	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer, int x, int y, int flags);

private:
	std::vector<Frame> m_frames;
	int m_currentFrame;
	float m_timer;
};


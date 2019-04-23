#include "ProgressBar.h"


void ProgressBar::Draw(aie::Renderer2D* renderer)
{
	//drawing the background of the bar 
	renderer->setRenderColour(1,0,0,1);
	renderer->drawBox(barXPos, barYPos, barWidth, barHeight);

	float ratio = barCurrentValue / barMaxValue;
	float full = barWidth * ratio;
	float offsetX = barXPos - (barWidth - full) * 0.5f;

	//drawing the actual bar 
	renderer->setRenderColour(0, 1, 0, 1);
	renderer->drawBox(offsetX, barYPos, full, barHeight);
	renderer->setRenderColour(1, 1, 1, 1);
}

void ProgressBar::SetValue(float value)
{
	barCurrentValue = value;
}

float ProgressBar::GetValue()
{
	return barCurrentValue;
}

ProgressBar::ProgressBar(float xPos, float yPos, float width, float height)
{
	barXPos = xPos;
	barYPos = yPos;
	barWidth = width;
	barHeight = height;
	barCurrentValue = 100;
	barMaxValue = 100;

}

ProgressBar::~ProgressBar()
{
}

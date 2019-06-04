#include "ProgressBar.h"

//passes in the name of the bootstrap renderer that will be used to render the bar to the screen
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

//passes in a float to assign to the bars current value
void ProgressBar::SetValue(float value)
{
	barCurrentValue = value;
}

//returns the value stored in the bars current value
float ProgressBar::GetValue()
{
	return barCurrentValue;
}

//passes in two floats to indicate the amount of pixels horizontally across or vertically along the screen the boxes will be placed
//passes in two floats to indicate the width and height of the boxes rendered 
//sets the current and max value of the bar
ProgressBar::ProgressBar(float xPos, float yPos, float width, float height)
{
	barXPos = xPos;
	barYPos = yPos;
	barWidth = width;
	barHeight = height;
	barCurrentValue = 16;
	barMaxValue = 16;
}

ProgressBar::~ProgressBar()
{
}

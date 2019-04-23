#pragma once
#include "Renderer2D.h"


class ProgressBar
{
public:
	ProgressBar(float xPos, float yPos, float width, float height);
	~ProgressBar();

	void Draw(aie::Renderer2D* renderer);
	void SetValue(float value);
	float GetValue();


private:

	float barXPos;				//bars position on the x axis
	float barYPos;				//bars position on the y axis
	float barWidth;				//width of the bar
	float barHeight;			//height of the bar
	float barCurrentValue;		//value that the bar currently represents
	float barMaxValue;			//max value the bar can indicate

};


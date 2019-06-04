#pragma once
#include "Renderer2D.h"

//handles the behaviour and properties of the players progress bar
class ProgressBar
{
public:

	//passes in two floats to indicate the amount of pixels horizontally across or vertically along the screen the boxes will be placed
	//passes in two floats to indicate the width and height of the boxes rendered 
	//sets the current and max value of the bar
	ProgressBar(float xPos, float yPos, float width, float height);
	~ProgressBar();

	//passes in the name of the bootstrap renderer that will be used to render the bar to the screen
	void Draw(aie::Renderer2D* renderer);
	//passes in a float to assign to the bars current value
	void SetValue(float value);
	//returns the value stored in the bars current value
	float GetValue();


private:

	float barXPos;				//bars position on the x axis
	float barYPos;				//bars position on the y axis
	float barWidth;				//width of the bar
	float barHeight;			//height of the bar
	float barCurrentValue;		//value that the bar currently represents
	float barMaxValue;			//max value the bar can indicate

};


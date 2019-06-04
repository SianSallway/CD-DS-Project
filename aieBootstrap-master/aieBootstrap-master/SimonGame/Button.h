#pragma once
#include "Renderer2D.h"
#include"Font.h"

//handles the behaviour and properties of the programs buttons
class Button
{
public:

	//passes in a char array that will be the text rendered on the button
	//passes in two floats to indicate the amount of pixels horizontally across or vertically along the screen the button will be placed
	//passes in two floats to indicate the width and height of the box rendered around the text of the button
	Button(const char* btnText, float xPos, float yPos, float width, float height);
	~Button();

	//passes in the name of the bootstrap renderer that will be used to render the button to the screen
	void Draw(aie::Renderer2D* renderer);
	//passes in the name of the bootstrap renderer that will be used to render the button to the screen
	void DrawRedGameButton(aie::Renderer2D* renderer);
	//passes in the name of the bootstrap renderer that will be used to render the button to the screen
	void DrawBlueGameButton(aie::Renderer2D* renderer);
	//passes in the name of the bootstrap renderer that will be used to render the button to the screen
	void DrawYellowGameButton(aie::Renderer2D* renderer);
	//passes in the name of the bootstrap renderer that will be used to render the button to the screen
	void DrawGreenGameButton(aie::Renderer2D* renderer);
	bool Update();

private:

	aie::Font* font;		//Button font
	char buttonText[64];	//Text for button

	float btnXPos;			//button x position
	float btnYPos;			//button y position
	float btnWidth;			//button width
	float btnHeight;		//button height
};


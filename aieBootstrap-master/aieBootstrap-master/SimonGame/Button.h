#pragma once
#include "Renderer2D.h"
#include"Font.h"

class Button
{
public:

	Button(const char* btnText, float xPos, float yPos, float width, float height);
	~Button();

	void Draw(aie::Renderer2D* renderer);
	void DrawRedGameButton(aie::Renderer2D* renderer);
	void DrawBlueGameButton(aie::Renderer2D* renderer);
	void DrawYellowGameButton(aie::Renderer2D* renderer);
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


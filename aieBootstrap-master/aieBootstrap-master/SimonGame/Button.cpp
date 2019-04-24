#include "Button.h"
#include "Input.h"
#include <string>


void Button::Draw(aie::Renderer2D* renderer)
{
	//drawing a box for the button background
	renderer->setRenderColour(0, 0.5f, 0.7f, 1);
	renderer->drawBox(btnXPos, btnYPos, btnWidth, btnHeight);
	renderer->setRenderColour(1, 1, 1, 1);

	//calculating the centred text position 
	float textWidth = font->getStringWidth(buttonText);
	float textHeight = font->getStringHeight(buttonText);
	float centredXPos = btnXPos - (textWidth * 0.5f) + 2;
	float centredYPos = btnYPos - (textHeight * 0.5f) + 5;

	//drawing the text onto the button
	renderer->drawText(font, buttonText, centredXPos, centredYPos);
}

void Button::DrawRedGameButton(aie::Renderer2D* renderer)
{
	renderer->setRenderColour(1, 0, 0, 1);
	renderer->drawBox(btnXPos, btnYPos, btnWidth, btnHeight);
	renderer->setRenderColour(1, 1, 1, 1);

}

void Button::DrawBlueGameButton(aie::Renderer2D* renderer)
{
	renderer->setRenderColour(0, 0, 225, 1);
	renderer->drawBox(btnXPos, btnYPos, btnWidth, btnHeight);
	renderer->setRenderColour(1, 1, 1, 1);

}

void Button::DrawYellowGameButton(aie::Renderer2D* renderer)
{
	renderer->setRenderColour(225, 255, 0, 1);
	renderer->drawBox(btnXPos, btnYPos, btnWidth, btnHeight);
	renderer->setRenderColour(1, 1, 1, 1);

}

void Button::DrawGreenGameButton(aie::Renderer2D* renderer)
{
	renderer->setRenderColour(0, 1, 0, 1);
	renderer->drawBox(btnXPos, btnYPos, btnWidth, btnHeight);
	renderer->setRenderColour(1, 1, 1, 1);

}

bool Button::Update()
{
	aie::Input* input = aie::Input::getInstance();

	//get mouse position 
	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();

	//calculating the 4 sides of the button 
	float left = btnXPos - (btnWidth * 0.5f);
	float right = btnXPos + (btnWidth * 0.5f);
	float bottom = btnYPos - (btnHeight * 0.5f);
	float top = btnYPos + (btnHeight * 0.5f);

	//checking if mouse is inside the box made by the 4 sides
	if (mouseX > left && mouseX < right && mouseY > bottom && mouseY < top)
	{
		//returns whether the mouse button is clicked while colliding
		return input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT);
	}

	return false;
}

Button::Button(const char* btnText, float xPos, float yPos, float width, float height)
{
	//Storing the text that will be on the button
	strcpy_s(buttonText, 64, btnText);

	//Load a font to display the buttons text 
	font = new aie::Font("./font/consolas.ttf", 24);

	//Storing the buttons position and dimentions
	btnXPos = xPos;
	btnYPos = yPos;
	btnWidth = width;
	btnHeight = height;
}


Button::~Button()
{
	delete font;
}

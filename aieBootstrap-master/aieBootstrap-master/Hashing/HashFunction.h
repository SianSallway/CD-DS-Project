#pragma once
#include <functional>
#include <string>
#include "Application.h"
#include "Renderer2D.h"

using namespace std;
class aie::Texture;


class HashFunction
{
public:
	HashFunction();
	~HashFunction();

	unsigned Hash(string data);

private:

	aie::Texture* button1Texture;
	aie::Texture* buttonTexture;
};


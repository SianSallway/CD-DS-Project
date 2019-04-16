#include "AnimatedSpriteApp.h"
#include <iostream>
#include <exception>

using namespace std;

int main() {
	
	// allocation
	auto app = new AnimatedSpriteApp();

	try 
	{
		// initialise and loop
		app->run("AIE", 1280, 720, false);
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

	// deallocation
	delete app;

	return 0;
}
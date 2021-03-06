#include "TreeNode.h"
#include "BinaryTreesApp.h"
#include <stdio.h>

extern aie::Font* g_systemFont;

void TreeNode::draw(aie::Renderer2D* renderer, int x, int y, bool selected)
{
	static char buffer[10];

	sprintf(buffer, "%d", m_value);

	renderer->setRenderColour(1, 1, 0);
	renderer->drawCircle(x, y, 30);

	renderer->setRenderColour(0, 0, 0);
	renderer->drawText(g_systemFont, buffer, x - 12, y - 10);

	if (selected == true)
	{
		renderer->setRenderColour(.5, .5, 0);
	}
	else
	{
		renderer->setRenderColour(0, 0, 0);
		renderer->drawCircle(x, y, 28);

		renderer->setRenderColour(1, 1, 1);
		renderer->drawText(g_systemFont, buffer, x-12, y-10);
	}
}

TreeNode::TreeNode(int value)
{
	SetData(value);
}


TreeNode::~TreeNode()
{
}

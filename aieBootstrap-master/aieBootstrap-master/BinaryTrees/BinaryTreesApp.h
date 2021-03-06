#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "TreeNode.h"
#include "BinaryTree.h"

class BinaryTreesApp : public aie::Application {
public:

	BinaryTreesApp();
	virtual ~BinaryTreesApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:
	aie::Renderer2D* m_2dRenderer;

	BinaryTree m_binaryTree;
	TreeNode* m_selectedNode;
};
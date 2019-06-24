#include "BinaryTree.h"
#include "TreeNode.h"
#include "BinaryTreesApp.h"
#include <iostream>

using namespace std;

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* selected)
{
	draw(renderer, m_pRoot, 640, 680, 640, selected);
}

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->hasLeft())
		{
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x - horizontalSpacing, y - 80);
			draw(renderer, pNode->getLeft(), x - horizontalSpacing, y - 80, horizontalSpacing, selected);
		}

		if (pNode->hasRight())
		{
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x + horizontalSpacing, y - 80);
			draw(renderer, pNode->getRight(), x + horizontalSpacing, y - 80, horizontalSpacing, selected);
		}

		pNode->draw(renderer, x, y, (selected == pNode));
	}
}

bool BinaryTree::isEmpty() const
{
	return m_pRoot == nullptr;
}

void BinaryTree::insert(int a_nValue)
{
	cout << "Insert value: " << a_nValue << endl;

	if (isEmpty())
	{
		m_pRoot = new TreeNode(a_nValue);
	}
	else
	{
		TreeNode* currentNode = m_pRoot;
		TreeNode* parentNode = nullptr;

		while (currentNode != NULL)
		{
			if (a_nValue < currentNode->getData())
			{
				parentNode = currentNode;
				currentNode = currentNode->getLeft();
			}
			else if (a_nValue > currentNode->getData())
			{
				parentNode = currentNode;
				currentNode = currentNode->getRight();
			}
			else
			{
				return;
			}
		}

		//Get the parent of the current node 
		TreeNode* nodeToInsert = new TreeNode(a_nValue);

		if (a_nValue < parentNode->getData())
		{
			parentNode->setLeft(nodeToInsert);
		}
		else
		{
			parentNode->setRight(nodeToInsert);
		}
	}
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent)
{
	TreeNode* currentNode = m_pRoot;
	TreeNode* currentParent = nullptr;

	while (currentNode != nullptr)
	{
		if (a_nSearchValue == currentNode->getData())
		{
			*ppOutNode = currentNode;
			*ppOutParent = currentParent;
			return true;

		}
		else if (a_nSearchValue < currentNode->getData())
		{
			currentParent = currentNode;
			currentNode = currentNode->getLeft();
		}
		else
		{
			currentParent = currentNode;
			currentNode = currentNode->getRight();
		}

	}

	// failure to find check
	return false;
}

TreeNode* BinaryTree::find(int a_nValue)
{
	TreeNode* ppOutNode;
	TreeNode* ppOutParent;

	bool wasFound = findNode(a_nValue, &ppOutNode, &ppOutParent);

	if (wasFound)
		return ppOutNode;
	else
		return nullptr;
}

void BinaryTree::remove(int a_nValue)
{
	find(a_nValue);
	cout << "found" << endl;

	TreeNode* currentNode;
	//TreeNode* minimumNode;

	currentNode->SetData(a_nValue);
	
	if (currentNode->hasRight())
	{
		currentNode->getRight();
	}
	else if (currentNode->hasLeft())
	{
		currentNode->getLeft();
	}
}

BinaryTree::BinaryTree()
{

}


BinaryTree::~BinaryTree()
{

}

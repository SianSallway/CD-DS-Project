#include "BinaryTree.h"
#include "TreeNode.h"
#include "BinaryTreesApp.h"
#include <iostream>

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
			draw(renderer, pNode->getRight(), x - horizontalSpacing, y - 80, horizontalSpacing, selected);
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
	std::cout << "Insert value: " << a_nValue << std::endl;

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

void BinaryTree::remove(int a_nValue)
{
	//find(a_nValue);
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent)
{
	/*currentNode = m_pRoot;
	valueToInsert = new TreeNode(a_nSearchValue);

	while (currentNode != NULL)
	{
		if (valueToInsert == currentNode)
		{
			return currentNode;
			return ppOutParent;
		}
		else if (valueToInsert <currentNode)
		{
			currentNode->setLeft(currentNode);
		}
		else if (valueToInsert > currentNode)
		{
			currentNode->setRight(currentNode);
		}
		else
		{
			return false;
		}

	}*/
	return false;
}

TreeNode* BinaryTree::find(int a_nValue)
{
	TreeNode* currentNode = m_pRoot;
	TreeNode* nodeToFind = new TreeNode(a_nValue);

	if (nodeToFind > currentNode->getLeft() || nodeToFind < currentNode->getRight())
	{
		return currentNode;
	}
	/*else if (a_nValue < currentNode->getData())
	{
		currentNode = currentNode->getLeft();
	}
	else if (a_nValue > currentNode->getData())
	{
		currentNode = currentNode->getRight();
	}
	else
	{

	}*/
	
}

BinaryTree::BinaryTree()
{

}


BinaryTree::~BinaryTree()
{

}

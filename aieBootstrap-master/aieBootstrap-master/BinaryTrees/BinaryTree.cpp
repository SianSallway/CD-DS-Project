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

/*	find the value in the tree, obtaining a pointer to the node and its parent
If the current node has a right branch,then
find the minimum value in the right branch by iterating down the left branch of the 
current node’s right child until there are no more left branch nodes
copy the value from this minimum node to the current node
find the minimum node’s parent node (the parent of the node you are deleting)
if you are deleting the parent’s left node
set this left child of the parent to the right child of the minimum node
if  you are deleting the parent’s right node
set the right child of the parent to the minimum node’s right child
If the current node has no right branch
if we are deleting the parent’s left child, set the left child of the parent to the left
child of the current node
If we are deleting the parent’s right child, set the right child of the parent to the left
child of the current nodeIf we are deleting the root, the root becomes the left child of the current node*/

void BinaryTree::remove(int a_nValue)
{
	find(a_nValue);
	cout << "found" << endl;

	TreeNode* currentNode = m_pRoot;
	TreeNode* minimumNode;
	TreeNode* minParentNode;



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

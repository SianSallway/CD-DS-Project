#pragma once

namespace aie
{
	class Renderer2D;
}


class TreeNode
{
public:
	TreeNode(int value);
	~TreeNode();

	bool hasLeft() 
	{
		return (m_left != nullptr);
	}

	bool hasRight()
	{
		return (m_right != nullptr);
	}

	int getData()
	{
		return m_value; 
	}
	
	TreeNode* getLeft() 
	{ 
		return m_left;
	}

	TreeNode* getRight()
	{ 
		return m_right;
	}

	void SetData(int value)
	{
		m_value = value;
	}

	void setLeft(TreeNode* node)
	{
		m_left = node;
	}

	void setRight(TreeNode* node)
	{
		m_right = node;
	}

	void draw(aie::Renderer2D* renderer, int x, int y, bool selected = false);

private:

	//this could also be a pointer to another object if you like
	int m_value;

	//node's children
	TreeNode* m_left = nullptr;
	TreeNode* m_right = nullptr;

};


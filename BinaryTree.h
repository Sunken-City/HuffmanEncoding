#pragma once

template <typename T> class BinaryTree
{
public:
	BinaryTree()
	{
		root = nullptr;
		numNodes = 0;
	}

	virtual ~BinaryTree();
	T* insert(T& data);
	int getNumNodes();

private:
	BinaryNode<T>* root;
	int numNodes;
	T* insert(T& newData, AvlNode<T>* &node);

	T* find(T& value, AvlNode<T> *node)
	{
		if (node != NULL)
		{
			//Is this our value? If so, return the node.
			if (value == node->data)
			{
				return &(node->data);
			}
			else if (value < node->data)
			{
				return find(value, node->left);
			}
			else
			{
				return find(value, node->right);
			}
		}
		else
		{
			return NULL;
		}
	}

	void clearTree(AvlNode<T> *node)
	{
		if (node != NULL)
		{
			clearTree(node->right);   // Recursively clear the right sub-tree
			clearTree(node->left);   // Recursively clear the left sub-tree
			delete node;         // Delete this node
		}
	}
};

template <typename T> class BinaryNode
{
public:
	T data;
	BinaryNode *left, *right;
	BinaryNode(T data, BinaryNode* left, BinaryNode* right);

};
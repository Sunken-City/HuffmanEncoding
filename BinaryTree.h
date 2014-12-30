#pragma once

template <typename T> class BinaryNode
{
public:
	T data;
	BinaryNode *left, *right;
	BinaryNode(T payload, BinaryNode* leftChild, BinaryNode* rightChild) : data(payload), left(leftChild), right(rightChild) {}
};

template <typename T> class BinaryTree
{
public:
	BinaryTree()
	{
		root = nullptr;
	}
	
	BinaryTree(BinaryNode<T>* rootNode)
	{
		root = rootNode;
	}

	virtual ~BinaryTree()
	{
		clearTree(root);
	}

	T* insert(T& data)
	{
		return insert(data, root);
	}

	T* find(T& value)
	{
		return find(value, this->root);
	}

	void postorderPrint(ostream & fout)
	{
		postorderPrint(root, fout);
	}

	BinaryNode<T>* getRoot()
	{
		return root;
	}

private:
	BinaryNode<T>* root;

	T* insert(T& newData, BinaryNode<T>* &node)
	{
		T* returnVal = NULL;

		//Base Case: If we don't have a node, then we insert here
		if (node == NULL)
		{
			node = new BinaryNode<T>(newData, NULL, NULL);
			returnVal = &(node->data);
		}

		//Otherwise, begin the descent.
		else if (newData < node->data)
			returnVal = insert(newData, node->left);

		else if (node->data < newData) //You only have to overload one operator, so we swap the two to use < again.
			returnVal = insert(newData, node->right);

		else
			returnVal = &(node->data);

		return returnVal;
	}

	T* find(T& value, BinaryNode<T> *node)
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

	void clearTree(BinaryNode<T> *node)
	{
		if (node != NULL)
		{
			clearTree(node->right);   // Recursively clear the right sub-tree
			clearTree(node->left);   // Recursively clear the left sub-tree
			delete node;         // Delete this node
		}
	}

	void postorderPrint(BinaryNode<T> *node, ostream & fout)
	{
		if (node != NULL)
		{
			postorderPrint(node->left, fout);   // Recursively print the left sub-tree
			postorderPrint(node->right, fout);   // Recursively print the right sub-tree
			fout << node->data << endl;
		}
	}
};
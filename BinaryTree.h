#pragma once

template <typename T> class BinaryNode : public Serializeable
{
public:
	T data;
	BinaryNode *left, *right;
	BinaryNode() : left(NULL), right(NULL) {};
	BinaryNode(T payload, BinaryNode* leftChild, BinaryNode* rightChild) : data(payload), left(leftChild), right(rightChild) {}

	bool isLeaf()
	{
		return (left == NULL) && (right == NULL);
	}

	void serialize(Serializer write)
	{
		this->data.serialize(write);
		char isNull = 'X';
		char notNull = 'O';
		//Write out a character to denote a branch as null
		if (this->left == NULL)
			write.IO<char>(isNull);
		else
		{
			write.IO<char>(notNull);
			this->left->serialize(write);
		}
		if (this->right == NULL)
			write.IO<char>(isNull);
		else
		{
			write.IO<char>(notNull);
			this->right->serialize(write);
		}
	}

	BinaryNode<T>* reconstruct(Serializer read)
	{
		BinaryNode<T>* node = new BinaryNode<T>();
		node->data.reconstruct(read);
		char isNull = 0x0;
		read.IO<char>(isNull);
		if (isNull == 'X')
			node->left = NULL;
		else
			node->left = BinaryNode::reconstruct(read);

		read.IO<char>(isNull);
		if (isNull == 'X')
			node->right = NULL;
		else
			node->right = BinaryNode::reconstruct(read);

		return node;
	}
};

template <typename T> class BinaryTree : public Serializeable
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
	
	BinaryNode<T>* getRoot()
	{
		return root;
	}

	void serialize(Serializer write)
	{
		this->root->serialize(write);
	}
	
	static BinaryTree<T>* reconstruct(Serializer read)
	{
		BinaryTree<T>* tree = new BinaryTree<T>();
		tree->root = tree->root->reconstruct(read);
		return tree;
	}

	BinaryNode<T>* findLeaf(BinaryNode<T>* currentNode, char huffmanBit)
	{
		if (currentNode == NULL)
			currentNode = root;
		if (huffmanBit == '0')
			return currentNode->left;
		else //if (bit == '1')
			return currentNode->right;
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

};
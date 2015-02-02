#pragma once

template <typename T> class BinaryNode : public Serializeable
{
public:
	T data;
	BinaryNode *left, *right;
	BinaryNode() : left(nullptr), right(nullptr) {};
	BinaryNode(T payload, BinaryNode* leftChild, BinaryNode* rightChild) : data(payload), left(leftChild), right(rightChild) {};
	//A few constants I defined to use in tree parsing.
	char isNull = 'X';
	char notNull = 'O';
	char nodeIsLeaf = 'L';
	char nodeIsNotLeaf = 'N';

	bool isLeaf()
	{
		return (left == nullptr) && (right == nullptr);
	}

	void serializeChild(BinaryNode* child, Serializer* write)
	{
		if (child == nullptr)
			write->IO<char>(isNull);
		else
		{
			write->IO<char>(notNull);
			child->serialize(write);
		}
	}

	void serialize(Serializer* write)
	{
		if (this->isLeaf())
		{
			write->IO<char>(nodeIsLeaf);
			this->data.serialize(write);
		}
		else
		{
			write->IO<char>(nodeIsNotLeaf);
			//Write out a character to denote a branch as null
			serializeChild(this->left, write);
			serializeChild(this->right, write);
		}
	}
	BinaryNode<T>* reconstructChild(Serializer* read)
	{
		BinaryNode<T>* child = nullptr;
		char isNodeNull = 0x0;
		read->IO<char>(isNodeNull);
		if (isNodeNull == 'O')
			child = BinaryNode::reconstruct(read);
		//We don't need to reconstruct null children.
		return child;
	}

	BinaryNode<T>* reconstruct(Serializer* read)
	{
		BinaryNode<T>* node = new BinaryNode<T>();
		char isNodeLeaf = 0x0;
		read->IO<char>(isNodeLeaf);
		if (isNodeLeaf == 'L')
		{
			node->data.reconstruct(read);
		}
		else //Don't even attempt to read the data if the node is a leaf, it's garbage anyway.
		{
			node->left = reconstructChild(read);
			node->right = reconstructChild(read);
		}
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

	void serialize(Serializer* write)
	{
		this->root->serialize(write);
	}

	static BinaryTree<T>* reconstruct(Serializer* read)
	{
		BinaryTree<T>* tree = new BinaryTree<T>();
		tree->root = tree->root->reconstruct(read);
		return tree;
	}

	BinaryNode<T>* findLeaf(BinaryNode<T>* currentNode, char huffmanBit)
	{
		if (currentNode == nullptr)
			currentNode = root;
		if (huffmanBit == '0')
			return currentNode->left;
		else
			return currentNode->right;
	}

private:
	BinaryNode<T>* root;

	T* insert(T& newData, BinaryNode<T>* &node)
	{
		T* returnVal = nullptr;

		//Base Case: If we don't have a node, then we insert here
		if (node == nullptr)
		{
			node = new BinaryNode<T>(newData, nullptr, nullptr);
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
		if (node != nullptr)
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
			return nullptr;
		}
	}

	void clearTree(BinaryNode<T> *node)
	{
		if (node != nullptr)
		{
			clearTree(node->right);   // Recursively clear the right sub-tree
			clearTree(node->left);   // Recursively clear the left sub-tree
			delete node;         // Delete this node
		}
	}

};
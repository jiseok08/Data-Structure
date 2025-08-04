#include <iostream>

using namespace std;

template <typename T>
class Set
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
	};

	Node* root;
public:
	Set()
	{
		root = nullptr;
	}

	void insert(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->left = nullptr;
		newNode->right = nullptr;

		if (root == nullptr)
		{
			root = newNode;
		}
		else if (root->data == newNode->data)
		{
			return;
		}
		else
		{
			Node* currentNode = root;

			while (currentNode != nullptr)
			{
				if (currentNode < newNode)
				{
					currentNode->right = newNode;
				}
				else if (currentNode > newNode)
				{
					currentNode->left = newNode;
				}
			}
		}
	}
};


int main()
{


	return 0;
}
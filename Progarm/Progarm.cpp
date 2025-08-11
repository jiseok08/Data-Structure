#include <iostream>

using namespace std;

template <typename T>
class Set
{
private:
	struct Node
	{
		T data;

		Node* left = nullptr;
		Node* right = nullptr;

		Node(T data)
		{
			this->data = data;
		}
	};

	Node* root;
public:
	Set()
	{
		root = nullptr;
	}

	void insert(T data)
	{
		Node* newNode = new Node(data);

		if (root == nullptr)
		{
			root = newNode;
		}
		else
		{
			Node* currentNode = root;

			while (currentNode != nullptr)
			{
				if (currentNode->data == data)
				{
					delete newNode;

					return;
				}
				else if (currentNode->data > data)
				{
					if (currentNode->left == nullptr)
					{
						currentNode->left = newNode;
						break;
					}
					else
					{
						currentNode = currentNode->left;
					}
				}
				else
				{
					if (currentNode->right == nullptr)
					{
						currentNode->right = newNode;

						break;
					}
					else
					{
						currentNode = currentNode->right;
					}
				}
			}
		}
	}

	void erase(T data)
	{
		Node* currentNode = root;
		Node* parrentNode = nullptr;

		while (currentNode != nullptr && currentNode->data != data)
		{
			parrentNode = currentNode;

			if (currentNode->data > data)
			{
				currentNode = currentNode->left;
			}
			else
			{
				currentNode = currentNode->right;
			}
		}

		if (currentNode == nullptr)
		{
			cout << "the data does not exist" << endl;
		}
		else if (currentNode->left == nullptr && currentNode->right == nullptr)
		{
			if (parrentNode != nullptr)
			{
				if (parrentNode->left == currentNode)
				{
					parrentNode->left = nullptr;
				}
				else
				{
					parrentNode->right = nullptr;
				}
			}
			else
			{
				root = nullptr;
			}
		}
		else if (currentNode->left == nullptr || currentNode->right == nullptr)
		{
			if (currentNode == root)
			{
				if (currentNode->left != nullptr)
				{
					root = currentNode->left;
				}
				else
				{
					root = currentNode->right;
				}
			}
			else
			{
				Node* childNode = nullptr;

				if (currentNode->left != nullptr)
				{
					childNode = currentNode->left;
				}
				else
				{
					childNode = currentNode->right;
				}

				if (parrentNode->left == currentNode)
				{
					parrentNode->left = childNode;
				}
				else
				{
					parrentNode->right = childNode;
				}
			}
		}
		else
		{
			Node* traceNode = currentNode->right;
			Node* childNode = nullptr;

			while (childNode->left != nullptr)
			{
				traceNode = childNode;

				childNode = traceNode->left;
			}

			traceNode = childNode->right;

			currentNode->right = traceNode;

			delete childNode;

			break;
		}

		delete currentNode;
	}

	void release(Node* root)
	{
		if (root != nullptr)
		{
			release(root->left);

			release(root->right);

			delete root;
		}
	}

	~Set()
	{
		release(root);
	}
};


int main()
{
	Set<int> set;

	set.insert(10);
	set.insert(17);
	set.insert(5);
	set.insert(3);
	set.insert(20);

	set.erase(17);

	return 0;
}
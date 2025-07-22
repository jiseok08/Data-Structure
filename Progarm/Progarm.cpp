#include <iostream>

using namespace std;

template <typename T>
class Stack
{
private:
	int count;
	int highset;
	int capacity;

	T* container;
public:
	Stack()
	{
		count = 0;
		highset = -1;
		capacity = 0;

		container = nullptr;
	}

	~Stack()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}
};

int main()
{

	return 0;
}
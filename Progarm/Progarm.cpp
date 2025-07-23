#include <iostream>

using namespace std;

#define SIZE 4

template <typename T>
class Queue
{
private:
	int rear;
	int fornt;

	T container[SIZE];
public:
	Queue()
	{
		rear = SIZE - 1;
		fornt = SIZE - 1;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

	void push(T data)
	{
		if (front == SIZE - (rear + 1))
		{
			cout << "circular queue overflow" << endl;
		}
	}

};

int main()
{


	return 0;
}
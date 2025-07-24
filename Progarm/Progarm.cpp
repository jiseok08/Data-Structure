#include <iostream>

using namespace std;

#define SIZE 4

template <typename T>
class PriorityQueue
{
private:
	int index;
	int capacity;

	T* container;
public:
	PriorityQueue()
	{
		index = 0;
		capacity = 0;

		container = nullptr;
	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (capacity <= index)
		{
			resize(capacity * 2);
		}

		container[index++] = data;

		int child = index - 1;
		int parent = (child - 1) / 2;

		while (child > 0)
		{
			if (container[parent] < container[child])
			{
				std::swap(container[parent], container[child]);
			}

			child = parent;
			parent = (child - 1) / 2;
		}
	}

	void pop()
	{
		
	}

	const bool& empty()
	{
		return index <= 0;
	}

	const int& size()
	{
		return index;
	}

	const T& top()
	{
		if (empty())
		{
			exit(1);
		}
		else
		{
			return container[0];
		}
	}

	void resize(int newSize)
	{
		// 1. capacity에 새로운 size값을 저장합니다.
		capacity = newSize;

		// 2. 새로운 포인터 변수를 생성해서 만들어진 
		//	  메모리 공간을 가리키도록 합니다.
		T* temporary = new T[capacity];

		// 3. 새로운 메모리 공간의 값을 초기화합니다.
		for (int i = 0; i < capacity; i++)
		{
			temporary[i] = NULL;
		}

		// 4. 기존 배열의 있는 값을 복사해서 새로운 
		//	  배열에 넣어줍니다.
		for (int i = 0; i < index; i++)
		{
			temporary[i] = container[i];
		}

		// 5, 기존 배열의 메모리를 해제합니다
		if (container != nullptr)
		{
			delete[] container;
		}

		// 6. 기존에 배열을 가리키던 포인터 변수의 값을 
		//    새로운 배열의 시작 주소로 가리킵니다.
		container = temporary;
	}

	~PriorityQueue()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}
};

int main()
{
	PriorityQueue<int> priorityQueue;

	priorityQueue.push(10);
	priorityQueue.push(31);
	priorityQueue.push(9);
	priorityQueue.push(15);

	cout << priorityQueue.top() << endl;

	return 0;
}
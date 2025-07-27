#include <iostream>

using namespace std;

template <typename T>
class Stack
{
private:
	int highset;
	int capacity;

	T* container;
public:
	Stack()
	{
		highset = -1;
		capacity = 0;

		container = nullptr;
	}

	void Resize(int newSize)
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
		for (int i = 0; i < highset + 1; i++)
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

	void push(T data)
	{
		if (capacity <= 0)
		{
			Resize(1);
		}
		else if (highset + 1 >= capacity)
		{
			Resize(capacity * 2);
		}

		container[++highset] = data;
	}

	void pop()
	{
		if (empty())
		{
			cout << "stack is empty" << endl;
		}
		else
		{
			container[highset--] = NULL;
		}
	}

	const bool& empty()
	{
		return highset <= -1;
	}

	const int& size()
	{
		return highset + 1;
	}

	const T& top()
	{
		if (container != nullptr)
		{
			return container[highset];
		}
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
	Stack<int> stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);


	while (stack.empty() == false)
	{
		cout << stack.top() << endl;

		stack.pop();
	}

	stack.pop();

	return 0;
}
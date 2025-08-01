#include <iostream>

using namespace std;

template <typename T>
class Graph
{
private:
	struct Node
	{
		T data;
		Node* next;

		Node(T data, Node* link = nullptr)
		{
			this->data = data;
			next = link;
		}
	};

	int size; // 정점의 개수
	int capacity; // 최대 용량
	int count; // 인접 리스트의 크기

	T* vertex; // 정점의 집합
	Node** list; // 인접 리스트

public:
	Graph()
	{
		size = 0;
		capacity = 0;
		count = 0;

		vertex = nullptr;
		list = nullptr;
	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (size >= capacity)
		{
			resize(capacity * 2);
		}

		vertex[size++] = data;
	}

	void edge(int i, int j)
	{
		if (size <= 0)
		{
			cout << "adjacency matrix is empty" << endl;
		}
		else if (size <= i || size <= j)
		{
			cout << "index out of range" << endl;
		}
		else
		{
			if (list == nullptr)
			{
				list = new Node* [size];

				for (int i = 0; i < size; i++)
				{
					list[i] = nullptr;
				}
				
				count = size;
			}
			else if (count < size)
			{
				resize();
			}

			list[i] = new Node(vertex[j], list[i]);
			list[j] = new Node(vertex[i], list[j]);
		}
	}

	void resize(int newSize)
	{
		// 1. capacity에 새로운 size값을 저장합니다.
		capacity = newSize;

		// 2. 새로운 포인터 변수를 생성해서 만들어진 
		//	  메모리 공간을 가리키도록 합니다.
		T* container = new T[capacity];

		// 3. 새로운 메모리 공간의 값을 초기화합니다.
		for (int i = 0; i < capacity; i++)
		{
			container[i] = NULL;
		}

		// 4. 기존 배열의 있는 값을 복사해서 새로운 
		//	  배열에 넣어줍니다.
		for (int i = 0; i < size; i++)
		{
			container[i] = vertex[i];
		}

		// 5, 기존 배열의 메모리를 해제합니다
		if (vertex != nullptr)
		{
			delete[] vertex;
		}

		// 6. 기존에 배열을 가리키던 포인터 변수의 값을 
		//    새로운 배열의 시작 주소로 가리킵니다.
		vertex = container;
	}

	void resize()
	{
		Node ** newlist = new Node * [size];

		for (int i = 0; i < size; i++)
		{
			if (list[i] != nullptr)
			{
				newlist[i] = list[i];
			}
			else
			{
				newlist[i] = nullptr;
			}
		}

		count = size;
	}

	~Graph()
	{
		if (list != nullptr)
		{
			for (int i = 0; i < count; i++)
			{
				Node* deleteNode = list[i];
				Node* nextNode = list[i];

				if (deleteNode == nullptr)
				{
					continue;
				}
				else
				{
					while (list[i] != nullptr)
					{
						nextNode = deleteNode->next;

						delete deleteNode;

						deleteNode = nextNode;
					}
				}
			}
		}
		delete[] list;

		delete[] vertex;
	}
};

int main()
{
	Graph<char> graph;

	graph.push('a');
	graph.push('b');
	graph.push('c');
	graph.push('d');

	graph.edge(1, 3);

	graph.push('e');

	graph.edge(2, 4);

	return 0;
}
#include <iostream>

using namespace std;

template <typename T>
class Graph
{
private:
	int size; // 정점의 개수
	int capacity; // 최대 용량

	int count; // 인접 행렬의 크기

	T* vertex; // 정점의 집합
	int** list; // 인접 행렬

public:
	Graph()
	{
		size = 0;
		count = 0;
		capacity = 0;

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
				count = size;

				list = new int* [size];

				for (int i = 0; i < size; i++)
				{
					list[i] = new int[size];

					for (int j = 0; j < size; j++)
					{
						list[i][j] = 0;
					}
				}
			}
			else if (count < size)
			{
				resize();
			}

			list[i][j] = 1;
			list[j][i] = 1;
		}
	}

	void resize()
	{
		int** newMatrix = new int* [size];

		for (int i = 0; i < size; i++)
		{
			newMatrix[i] = new int[size] {0};
		}

		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count; j++)
			{
				newMatrix[i][j] = list[i][j];
			}
		}

		if (list != nullptr)
		{
			for (int i = 0; i < count; i++)
			{
				delete[] list[i];
			}

			delete[] list;
		}

		list = newMatrix;

		count = size;
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

	friend ostream& operator << (ostream& ostream, const Graph<T>& graph)
	{
		ostream << "  ";

		for (int i = 0; i < graph.size; i++)
		{
			ostream << graph.vertex[i] << " ";
		}

		ostream << endl;

		for (int i = 0; i < graph.count; i++)
		{
			ostream << graph.vertex[i] << " ";

			for (int j = 0; j < graph.count; j++)
			{
				ostream << graph.list[i][j] << " ";
			}

			ostream << endl;
		}

		return ostream;
	}

	~Graph()
	{
		if (list != nullptr)
		{
			for (int i = 0; i < count; i++)
			{
				delete[] list[i];
			}

			delete[] list;
		}

		delete[] vertex;
	}
};

int main()
{
	Graph<char> graph;

	graph.push('A');
	graph.push('B');
	graph.push('C');

	graph.edge(0, 1);

	graph.push('D');

	graph.edge(3, 1);

	cout << graph << endl;

	return 0;
}
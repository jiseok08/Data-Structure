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
	int** matrix; // 인접 행렬

public:
	Graph()
	{
		size = 0;
		count = 0;
		capacity = 0;

		vertex = nullptr;
		matrix = nullptr;
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
			if (matrix == nullptr)
			{
				count = size;

				matrix = new int* [size];

				for (int i = 0; i < size; i++)
				{
					matrix[i] = new int[size];

					for (int j = 0; j < size; j++)
					{
						matrix[i][j] = 0;
					}
				}
			}

			matrix[i][j] = 1;
			matrix[j][i] = 1;
		}
	}

	void resize(int newSize)
	{
		// 1. capacity에 새로운 size값을 저장합니다.
		capacity = newSize;

		// 2. 새로운 포인터 변수를 생성해서 만들어진 
		//	  메모리 공간을 가리키도록 합니다.
		T* conatiner = new T[capacity];

		// 3. 새로운 메모리 공간의 값을 초기화합니다.
		for (int i = 0; i < capacity; i++)
		{
			conatiner[i] = NULL;
		}

		// 4. 기존 배열의 있는 값을 복사해서 새로운 
		//	  배열에 넣어줍니다.
		for (int i = 0; i < size; i++)
		{
			conatiner[i] = vertex[i];
		}

		// 5, 기존 배열의 메모리를 해제합니다
		if (vertex != nullptr)
		{
			delete[] vertex;
		}

		// 6. 기존에 배열을 가리키던 포인터 변수의 값을 
		//    새로운 배열의 시작 주소로 가리킵니다.
		vertex = conatiner;
	}

	~Graph()
	{
		if (matrix != nullptr)
		{
			for (int i = 0; i < size; i++)
			{
				delete[] matrix[i];
			}

			delete[] matrix;
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

	return 0;
}
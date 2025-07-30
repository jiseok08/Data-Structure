#include <iostream>

using namespace std;

template <typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;

		Node* next;
	};

	struct Bucket
	{
		int count;
		Node* head;
	};

	int size;
	int capacity;
	Bucket* bucket;
public:
	HashTable()
	{
		size = 8;
		capacity = 0;

		bucket = new Bucket[size];

		for (int i = 0; i < size; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}

	const float& load_factor()
	{
		return (float)capacity / size;
	}

	unsigned int hash_function(KEY key)
	{
		return (unsigned int)key % size;
	}

	void insert(KEY key, VALUE value)
	{
		// 해시 함수를 통해서 값을 받는 임시 변수
		int hashIndex = hash_function(key);

		// 새로운 노드를 생성합니다.
		Node* newNode = new Node;

		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;

		// 노드가 1개라도 존재하지 않는다면

		if (bucket[hashIndex].count == 0)
		{
			// bucket[hashIndex]의 head 포인터가 newNode를 가리키게 합니다.
			bucket[hashIndex].head = newNode;
		}
		else
		{
			newNode->next = bucket[hashIndex].head;

			bucket[hashIndex].head = newNode;
		}

		capacity++;

		// bucket[hashIndex]의 count를 증가시킵니다.
		bucket[hashIndex].count++;
	}

	void erase(KEY key)
	{
		// 해시 값을 통해 값을 받는 임시 변수
		int hashIndex = hash_function(key);

		// Node를 탐색할 수 있는 포인터 변수 선언
		Node* currentNode = bucket[hashIndex].head;

		// 이전 Node를 저장할 수 있는 포인터 변수
		Node* previousNode = nullptr;

		// currentNode가 nullptr과 같다면 함수를 종료합니다.
		if (currentNode == nullptr)
		{
			cout << "not key found" << endl;

			return;
		}
		else
		{
			while (currentNode != nullptr)
			{
				if (currentNode->key == key)
				{
					if (currentNode == bucket[hashIndex].head)
					{
						bucket[hashIndex].head = currentNode->next;
					}
					else
					{
						previousNode->next = currentNode->next;
					}

					capacity--;

					bucket[hashIndex].count--;

					delete currentNode;

					return;
				}
				else
				{
					previousNode = currentNode;

					currentNode = currentNode->next;
				}
			}
		}

		cout << "not key found" << endl;
	}

	const int& bucket_count()
	{
		return size;
	}

	~HashTable()
	{


		for (int i = 0; i < size; i++)
		{
			if (bucket[i].head != nullptr)
			{
				Node* deleteNode = bucket[i].head;
				Node* nextNode = bucket[i].head;

				while (deleteNode != nullptr)
				{
					nextNode = deleteNode->next;

					delete deleteNode;

					deleteNode = nextNode;
				}
			}
		}

		delete[] bucket;
	}
};

int main()
{
	HashTable<int, int> hashtable;

	hashtable.insert(4, 11);
	hashtable.insert(3, 22);
	hashtable.insert(12, 99);
	hashtable.insert(12, 99);
	hashtable.insert(12, 99);
	hashtable.insert(12, 99);
	hashtable.insert(12, 99);
	hashtable.insert(12, 99); // 8개

	cout << hashtable.load_factor() << endl;

	return 0;
}
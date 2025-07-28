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
	Bucket * bucket;
public:
	HashTable()
	{
		size = 8;

		bucket = new Bucket[size];
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

		for (int i = 0; i < bucket[hashIndex].count; i++)
		{
			previousNode = currentNode;
			currentNode = currentNode->next;

			if (currentNode->key == key)
			{
				previousNode->next = currentNode->next;

				delete currentNode;

				return;
			}
		}

		cout << "not key found" << endl;
	}

	const int& bucket_count()
	{
		return size;
	}
};

int main()
{
	HashTable<const char*, int> hashtable;

	hashtable.insert("Hi", 11);
	hashtable.insert("Hello", 22);
	hashtable.insert("Good", 99);

	hashtable.erase("Hi");
	hashtable.erase("aaa");

	return 0;
}
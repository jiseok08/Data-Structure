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

	const int& hash_function(KEY key)
	{

	}
};

int main()
{
	HashTable<const char*, int> hashtable;

	return 0;
}
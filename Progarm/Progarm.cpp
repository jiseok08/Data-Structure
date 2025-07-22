#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
	int count;
	int capacity;

	T* pointer;
public:	
	Vector()
	{
		count = 0;
		capacity = 0;

		pointer = nullptr;
	}
};

int main()
{


	return 0;
}
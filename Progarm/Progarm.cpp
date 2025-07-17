#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node* previous;
        Node* next;
    };

    int size;
    Node* head;
    Node* tail;

public:
    List()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void push_front(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->next = nullptr;
        newNode->previous = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->previous = newNode;
            newNode->next = head;

            head = newNode;
        }

        size++;
    }

    void pop_front()
    {
        if(head == nullptr) cout << "linked list is empty" << endl;
        else
        {
            Node* deleteNode = head;

            if (size == 1)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                tail->next = newNode;       
                newNode->previous = tail;

                tail = newNode;
            }

            delete deleteNode;

            size--;
        }
    }

    void push_back(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->next = nullptr;
        newNode->previous = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = tail;
            tail->previous = newNode;

            tail = newNode;
        }

        size++;
    }

    ~List()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }
};


int main()
{
    List<int> list;

    list.push_back(15);
    list.push_back(10);
    list.push_back(5);

    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();

    return 0;
}

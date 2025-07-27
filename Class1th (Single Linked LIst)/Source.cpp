#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node* next;
    };

    int size;
    Node* head;
public:
    List()
    {
        size = 0;
        head = nullptr;
    }

    void push_front(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;

            newNode->next = nullptr;
        }
        else
        {
            newNode->next = head;

            head = newNode;
        }

        size++;
    }

    void pop_front()
    {
        if (head == nullptr) cout << "linked list is empty" << endl;
        else
        {
            Node* deleteNode = head;

            head = head->next;

            delete deleteNode;

            size--;
        }
    }

    void push_back(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* currentNode = head;

            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }

            currentNode->next = newNode;
        }

        size++;
    }

    void pop_back()
    {

        if (head == nullptr) cout << "linked list is empty" << endl;
        else
        {
            Node* deleteNode = head;
            Node* previousNode = nullptr;

            if (size == 1)
            {
                head = deleteNode->next;

                delete deleteNode;
            }
            else
            {
                while (deleteNode->next != nullptr)
                {
                    previousNode = deleteNode;

                    deleteNode = deleteNode->next;
                }

                previousNode->next = nullptr;

                delete deleteNode;
            }


            size--;
        }
    }

    void remove(T data)
    {
        if (head == nullptr) return;
        else
        {
            Node* deleteNode = head;
            Node* previousNode = nullptr;

            while (deleteNode != nullptr)
            {
                if (deleteNode->data == data)
                {
                    if (deleteNode == head)
                    {
                        pop_front();

                        deleteNode = head;
                        previousNode = head;
                    }
                    else
                    {
                        previousNode->next = deleteNode->next;

                        delete deleteNode;

                        size--;

                        deleteNode = head;

                        previousNode = deleteNode;
                    }
                }
                else
                {
                    previousNode = deleteNode;

                    deleteNode = deleteNode->next;
                }
            }
        }

        return;
    }

    bool empty()
    {
        if (head == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
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

    list.push_front(20);
    list.push_front(10);
    list.push_front(5);

    list.remove(10);

    cout << list.empty() << endl;

    return 0;
}

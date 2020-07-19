#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>

template<class T>
class LinkedList
{
public:

    template<class T>
    class Node
    {
    public:
        Node(T value, Node *next): value(value),
                                   next(next)
        {
        }

        T value;
        Node<T> *next;
    };

    LinkedList(): size(0),
                  head(nullptr),
                  tail(nullptr)
    {
    }

    ~LinkedList()
    {
    }

    void push_front(T value)
    {

    }

    void push_back(T value)
    {
        Node<T> *node = new Node(value, nullptr);
        tail->next = node;
        tail = node;
    }

    void print()
    {
        Node<T> *node = head;
        std::cout << "Linked List: ";
        std::cout << node->value;
        while(node != nullptr)
        {
            std::cout << ", " << next->value;
        }
        std::cout << std::endl;
    }

private:
    int size;
    Node<T> *head;
    Node<T> *tail;
};

int main()
{
    LinkedList<int> *linkedList = new LinkedList();
    linkedList->push_back(1);
    linkedList->push_back(2);
    linkedList->push_back(3);
    linkedList->push_back(4);   
}

#endif // __LINKED_LIST_H__
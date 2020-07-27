#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>
#include <unordered_map>

template<class T>
class LinkedList
{
public:

    // template<class T>
    class Node
    {
    public:
        Node(T value, Node *next): value(value),
                                   next(next)
        {
        }

        T value;
        Node *next;
    };

    LinkedList(): size(0),
                  head(nullptr),
                  tail(nullptr)
    {
    }

    ~LinkedList()
    {
        erase_all();
    }

    void push_front(T value)
    {
        Node *node = new Node(value, nullptr);
        if (size == 0)
        {
            head = node;
        }
        else if (size == 1)
        {
            node->next = head;
            tail = head;
            head = node;
        }
        else
        {
            node->next = head;
            head = node;
        }
        
        size++;
    }

    void push_back(T value)
    {
        Node *node = new Node(value, nullptr);
        if (size == 0)
        {
            head = node;
        }
        else if(size == 1)
        {
            head->next = node;
            tail = node;
        }
        else
        {
           tail->next = node;
           tail = node;
        }
        size++; 
    }
    
    void erase_all()
    {
        Node *node = head;
        while (node != nullptr)
        {
            Node *next = node->next;
            delete node;
            node = next;            
        }
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    // Temporal complexity: O(n)
    // Spacial complexity: O(n)
    void remove_duplicates()
    {
        if (size == 0) return;

        Node *previous = nullptr;
        Node *node = head;
        std::unordered_map<T, int> values_map = {};
        while (node != nullptr)
        {
            try
            {
                int valueCount = values_map.at(node->value);
                values_map[node->value] += 1;
                // Value duplicated, already in values map
                Node* duplicated = node;
                node = duplicated->next;
                remove(duplicated, previous);
            }
            catch(const std::out_of_range& e)
            {
                // First occurrence of value, insert to map
                values_map[node->value] = 1;
                previous = node;
                node = node->next;
            }
        }
    }

    void remove(Node *node, Node *previous)
    {
        if (node == head)
        {
            head = node->next;
        }
        else if (node == tail)
        {
            previous->next = nullptr;
            tail = previous;
        }
        else
        {
            previous->next = node->next;
        }
        delete node;
        size--;
    }

    void print()
    {
        if (size == 0)
        {
            std::cout << "Empty Linked List" << std::endl;
            return;
        }

        std::cout << "Linked List size=" << size << std::endl;

        Node *node = head;
        std::cout << "Linked List: ";
        std::cout << node->value;
        node = node->next;
        while (node != nullptr)
        {
            std::cout << ", " << node->value;
            node = node->next;
        }
        std::cout << std::endl;
    }

private:
    int size;
    Node *head;
    Node *tail;
};

#endif // __LINKED_LIST_H__
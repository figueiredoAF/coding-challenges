#include "linked-list.h"
#include <string>

int main()
{
    LinkedList<std::string> *linkedList = new LinkedList<std::string>();
    
    linkedList->push_back("Alex");
    linkedList->push_front("Alex");
    linkedList->push_back("Alex");
    linkedList->push_front("Alex");
    linkedList->push_front("Andre");

    std::cout << "Initial Linked List:" << std::endl; 
    linkedList->print();

    std::cout << "Removing duplicates..." << std::endl;
    linkedList->remove_duplicates();

    std::cout << "Final Linked List:" << std::endl; 
    linkedList->print();

    linkedList->erase_all();
    delete linkedList; 
}
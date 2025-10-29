// guard code
#pragma once

// includes
#include <iostream>
#include "Node.hpp"

// standard singly linked list we have implemented 10000 times for class. 
// 
template <typename T>
class LinkedList
{
    public:
        // constructor
        LinkedList()
        {
            pHead = nullptr; // init the start of the list
        }
    
        // destructor
        ~LinkedList()
        {
            Node<T>* pCurr = pHead;

            // frees up the entire linked list
            while(pCurr != nullptr)
            {
                Node<T>* temp = pCurr; // stores the node we want to delete in a temp variable
                pCurr = pCurr->pNext; // moves to next node
                delete temp; // deletes the old node
            }
        }

        // function to insert an item (new node) to the front of the linked list
        void insertFrontLinkedList(const T& newNode)
        {
            // create a new node to insert into the list
            Node<T>* fNode = new Node<T>(newNode);
            // place in the front of the list
            fNode->pNext = pHead;
            pHead = fNode
        }

        // function to print all of the contents of the linked list (the ID and Name of every product in the list)
        void printLinkedList() const
        {
            Node<T>* pCurr = pHead;

            while(pCurr != nullptr)
            {
                if (pCurr->data != nullptr) // keep going as long as the current node has data
                {
                    pCurr->data->printIDandName(); // prints the id and name of the current node
                }
                pCurr = pCurr->pNext; // move to next node
            }
        }

        // function to check if the linked list is empty
        bool isLinkedListEmpty() const
        {
            return pHead == nullptr;
        }

    private:
        Node<T>* pHead;

};
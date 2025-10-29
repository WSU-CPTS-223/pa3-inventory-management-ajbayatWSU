// guard code
#pragma once

// templates for the node used in the linked list
template <typename T>
struct Node
{
    T data; // holds the contents of the node
    Node<T>* pNext; // points to next node

    Node(const T& newData)
    {
        data = newData;
        pNext = nullptr;
    }
};
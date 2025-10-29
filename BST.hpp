// guard code
#pragma once

// includes
//#include <iostream>
//#include <string>
#include <BSTNode.hpp>

// template for a simple non-balancing BST
// used to look up for the 2 commands
// note: this BST does NOT own the Product objects, it only points to them
// cleanup of those objects is handled in InventorySystem
template <typename I, typename P> // I - ID (key)
                                  // P - Product category (value)
class BST
{
public:
    // constructor
    BST()
    {
        pRoot = nullptr;
    }

    // destructor
    ~BST()
    {
        destroyBST(); // delete the entire BST from memory
    }

    // function to insert a node into a BST (can start one) 
    void insertNodeBST(const I& newlyInsertedID, const P& newlyInsertedProductCat)
    {
        // if the tree is empty make a new tree
        if (pRoot == nullptr)
        {
            pRoot = new BSTNode<I, P>(newlyInsertedID, newlyInsertedProductCat);
            return;
        }

        BSTNode<I, P>* pCurr = pRoot;
        BSTNode<I, P>* pParent = nullptr; // pointer to the parent node

        // traverse bst as long as data is present
        while (pCurr != nullptr)
        {
            pParent = pCurr;

            // go left
            if (newlyInsertedID < pCurr->id)
            {
                pCurr = pCurr->pLeft;
            }

            // go right
            else if (pCurr->id < newlyInsertedID)
            {
                pCurr = pCurr->pRight;
            }

            // if same key is found, update the key
            else
            {
                pCurr->productCat = newlyInsertedProductCat;
                return;
            }
        }

        // make a new node and link it to the correct side
        BSTNode<I, P>* pNewBSTNode = new BSTNode<I, P>(newlyInsertedID, newlyInsertedProductCat);

        // connect to left?
        if (newlyInsertedID < pParent->id)
        {
            pParent->pLeft = pNewBSTNode;
        }

        // connect to right?
        else
        {
            pParent->pRight = pNewBSTNode;
        }
    }

    // function to find an ID (key) in the tree
    bool lookup(const I& searchID, P& foundProductCat)
    {
        BSTNode<I, P>* pCurr = pRoot;

        // traverse bst as long as data is present
        while (pCurr != nullptr)
        {
            // found id matching the search
            if (searchID == pCurr->id)
            {
                foundProductCat = pCurr->productCat;
                return true;
            }
            // go left
            else if (searchID < pCurr->id)
            {
                pCurr = pCurr->pLeft;
            }
            else
            {
                pCurr = pCurr->pRight;
            }
        }

        // if the search returns no match
        return false;
    }

    private:
        BSTNode<I, P>* pRoot; // pointer to the root of the BST

        // function to free the tree from memory
        // had to make this iterative because I kept blowing the stack
        // this is because in the worst case my BST will be a linked list 10k nodes deep :(
        void destroyBST()
        {
            // check for empty tree
            if (pRoot == nullptr)
            {
                return;
            }

            int maxCapacity = 20000, // this had to be huge since the csv file has about 10k entries
                topStack = -1; // empty stack so no top yet

            BSTNode<I, P>** stack = new BSTNode<I, P>*[maxCapacity]; // create the stack

            BSTNode<I, P>* pPrev = nullptr;
            BSTNode<I, P>* pCurr = pRoot;

            // main loop to destroy the BST
            while (pCurr != nullptr || topStack >= 0) // as long as the stack as contents keep going
            {
                if (pCurr != nullptr)
                {
                    stack[++topStack] = pCurr; // push node to the stack
                    pCurr = pCurr->pLeft; // go left
                }

                // cant go left anymore
                else
                {
                    BSTNode<I, P>* peek = stack[topStack];

                    // check right subtree
                    if (peek->pRight != nullptr && pPrev != peek->pRight)
                    {
                        pCurr = peek->pRight;
                    }

                    // found the node we can delete
                    else
                    {
                        --topStack;
                        pPrev = peek;
                        delete peek;
                    }
                }
            }
            
            delete[] stack;
            pRoot = nullptr;
        }
};
// guard code
#pragma once

// template for the BSTNode
template <typename I, typename P> // I - ID (key)
                                  // P - Product category (value)
struct BSTNode
{
    I id;
    P productCat;

    // subtree ptrs
    BSTNode<I, P>* pLeft;
    BSTNode<I, P>* pRight;



    // function to make a new BSTNode
    BSTNode(const I& newID, const P& newProductCat)
    {
        id = newID;
        productCat = newProductCat;
        pLeft = nullptr;
        pRight = nullptr;
    }
};
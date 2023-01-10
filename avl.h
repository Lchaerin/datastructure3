#pragma once
#include "bst.h"

using namespace std;

class AVLTree: public BinarySearchTree {
public:
    AVLTree() { };
    ~AVLTree() { };

    int insertion(int key);
    int deletion(int key);

private:
    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////
    void _searchExist(Node *node, int key_val);
    void _checking_bf(Node *node);
    void _inserting(Node *node, int key_val);
    void _LL_rotation(Node *pivot);
    void _RR_rotation(Node *pivot);
    void _snrs(Node *node);
    void _deleting(int key);
    void _marking_height(Node *node);
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};
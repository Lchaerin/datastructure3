#include "tree.h"
#include "bst.h"
#include <iostream>
#include <string>

using namespace std;
bool existance=false;
Node *nodeToDelete=NULL;
Node *SNRS=NULL;//smallest node in right subtree
Node *deleteNodeParnet;
int BinarySearchTree::insertion(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    if (_root==NULL){
        _root=new Node(key);
        return 0;
    }
    else{
        searchExist(_root,key);
        if(existance){
            existance=false;
            return -1;
        }
        else{
            inserting(_root, key);
            return 0;
        }
    }
    

    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int BinarySearchTree::deletion(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    if (_root==NULL){
        return -1;
    }
    else{
        searchExist(_root,key);
        if(existance){
            if(nodeToDelete->right==NULL&&nodeToDelete->left==NULL){
                if(_root->key==key){
                    _root=NULL;
                }
                else if(deleteNodeParnet->right!=NULL){
                    if(deleteNodeParnet->right->key==key){
                    deleteNodeParnet->right=NULL;
                    }else{
                    deleteNodeParnet->left=NULL;
                }
                }
                else{
                    deleteNodeParnet->left=NULL;
                }
            }
            else if(nodeToDelete->right==NULL&&nodeToDelete->left!=NULL){
                nodeToDelete->key=nodeToDelete->left->key;
                nodeToDelete->left=nodeToDelete->left->left;
            }
            else if(nodeToDelete->right!=NULL&&nodeToDelete->left==NULL){
                nodeToDelete->key=nodeToDelete->right->key;
                nodeToDelete->right=nodeToDelete->right->right;
            }
            else{
                if(nodeToDelete->right->left!=NULL){
                    snrs(nodeToDelete);
                    nodeToDelete->key=SNRS->key;
                    if(SNRS->right!=NULL){
                        SNRS->key=SNRS->right->key;
                        SNRS->right=SNRS->right->right;
                    }
                    else{
                        nodeToDelete->right->left=NULL;
                    }
                }
                else{
                    nodeToDelete->key=nodeToDelete->right->key;
                    nodeToDelete->right=nodeToDelete->right->right;
                }
            }
            existance=false;
            return 0;
        }
        else{
            return -1;
        }
    }

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

void BinarySearchTree::snrs(Node *node){
    if(node->right!=NULL){
        node=node->right;
        while(node->left!=NULL){
            node=node->left;
        }
    }
    SNRS=node;
}

void BinarySearchTree::searchExist(Node *node, int key_val){
    if(node->key==key_val){
        existance=true;
        nodeToDelete=node;
    }
    if(node->left!=NULL){
        if(node->left->key==key_val){
            deleteNodeParnet=node;
        }
      searchExist(node->left, key_val);
      }
    if(node->right != NULL){
        if(node->right->key==key_val){
            deleteNodeParnet=node;
        }
      searchExist(node->right, key_val);
    }
}


void BinarySearchTree::inserting(Node *node, int key_val){
    if((node->key)>key_val){
        if(node->left==NULL){
            Node* temp = new Node(key_val);
            temp->key=key_val;
            node->left=temp;
        }
        else{
            inserting(node->left, key_val);
        }
    }
    else{
        if(node->right==NULL){
            Node* temp = new Node(key_val);
            temp->key=key_val;
            node->right=temp;
        }
        else{
            inserting(node->right, key_val);
        }
    }
}

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////

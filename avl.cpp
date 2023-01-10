#include "tree.h"
#include "bst.h"
#include "avl.h"
#include <iostream>
#include <string>

using namespace std;


/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////
bool _existance=false;
Node *_nodeToDelete=NULL;
Node *_SNRS=NULL;//smallest node in right subtree
Node *_rightest;
Node *_pivot=NULL;
Node *_deleteNodeParnet;
int _pivot_bf=0;

void AVLTree::_searchExist(Node *node, int key_val){
    if(node->key==key_val){
        _existance=true;
        _nodeToDelete=node;
    }
    if(node->left!=NULL){
        if(node->left->key==key_val){
            _deleteNodeParnet=node;
        }
      _searchExist(node->left, key_val);
      }
    if(node->right != NULL){
        if(node->right->key==key_val){
            _deleteNodeParnet=node;
        }
      _searchExist(node->right, key_val);
    }
}


void AVLTree::_marking_height(Node *node){
    if(node->left!=NULL){
      _marking_height(node->left);
      }
    if(node->right != NULL){
      _marking_height(node->right);
    }
    if(node->left!=NULL&&node->right!=NULL){
        node->height=max(node->left->height,node->right->height)+1;
    }
    else if(node->left!=NULL||node->right!=NULL){
        node->left!=NULL?node->height=(node->left->height)+1:node->height=(node->right->height)+1;
    }
    else{
        node->height=0;
    }
}

void AVLTree::_checking_bf(Node *node){
    int bf=0;
    if(node->left!=NULL&&node->right!=NULL){
        bf=(node->left->height)-(node->right->height);
    }
    else if(node->left==NULL&&node->right==NULL){
        bf=0;
    }
    else if(node->left!=NULL||node->right!=NULL){
        node->left!=NULL?bf=(node->left->height)+1:bf=-(node->right->height)-1;
    }
    if(abs(bf)>1){
        _pivot=node;
        _pivot_bf=bf;
    }
    if(node->left!=NULL){
      _checking_bf(node->left);
      }
    if(node->right != NULL){
      _checking_bf(node->right);
    }
}

void AVLTree::_inserting(Node *node, int key_val){
    if((node->key)>key_val){
        if(node->left==NULL){
            Node* temp = new Node(key_val);
            temp->key=key_val;
            node->left=temp;
        }
        else{
            _inserting(node->left, key_val);
        }
    }
    else{
        if(node->right==NULL){
            Node* temp = new Node(key_val);
            temp->key=key_val;
            node->right=temp;
        }
        else{
            _inserting(node->right, key_val);
        }
    }
}

void AVLTree::_LL_rotation(Node *pivot){
    Node* new_node = new Node(pivot->key);
    pivot->left->right!=NULL?new_node->left=pivot->left->right:new_node->left=NULL;
    new_node->right=pivot->right;
    pivot->key=pivot->left->key;
    pivot->left=pivot->left->left;
    pivot->right=new_node;
}

void AVLTree::_RR_rotation(Node *pivot){
    Node* new_node = new Node(pivot->key);
    new_node->key=pivot->key;
    pivot->right->left!=NULL?new_node->right=pivot->right->left:new_node->right=NULL;
    new_node->left=pivot->left;
    pivot->key=pivot->right->key;
    pivot->right=pivot->right->right;
    pivot->left=new_node;
}

void AVLTree::_snrs(Node *node){
    if(node->right!=NULL){
        node=node->right;
        while(node->left!=NULL){
            node=node->left;
        }
    }
    _SNRS=node;
}

void AVLTree::_deleting(int key){
    if(_nodeToDelete->right==NULL&&_nodeToDelete->left==NULL){
                if(_root->key==key){
                    _root=NULL;
                }
                else if(_deleteNodeParnet->right!=NULL){
                    if(_deleteNodeParnet->right->key==key){
                    _deleteNodeParnet->right=NULL;
                    }else{
                        _deleteNodeParnet->left=NULL;
                    }
                }
                else{
                    _deleteNodeParnet->left=NULL;
                }
            }
            else if(_nodeToDelete->right==NULL&&_nodeToDelete->left!=NULL){
                _nodeToDelete->key=_nodeToDelete->left->key;
                _nodeToDelete->left=_nodeToDelete->left->left;
            }
            else if(_nodeToDelete->right!=NULL&&_nodeToDelete->left==NULL){
                _nodeToDelete->key=_nodeToDelete->right->key;
                _nodeToDelete->right=_nodeToDelete->right->right;
            }
            else{
                if(_nodeToDelete->right->left!=NULL){
                    _snrs(_nodeToDelete);
                    _nodeToDelete->key=_SNRS->key;
                    if(_SNRS->right!=NULL){
                        _SNRS->key=_SNRS->right->key;
                        _SNRS->right=_SNRS->right->right;
                    }
                    else{
                        _nodeToDelete->right->left=NULL;
                    }
                }
                else{
                    _nodeToDelete->key=_nodeToDelete->right->key;
                    _nodeToDelete->right=_nodeToDelete->right->right;
                }
            }
}

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////


int AVLTree::insertion(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    if (_root==NULL){
        _root=new Node(key);
    }
    else{
        _searchExist(_root,key);
        if(_existance){
            _existance=false;
            return -1;
        }
        else{
            _inserting(_root, key);
        }
    }
    _pivot_bf=0;
    _marking_height(_root);
    _checking_bf(_root);
    if(_pivot_bf==2){
        int bfbf;
        if(_pivot->left->left!=NULL&&_pivot->left->right!=NULL){
            bfbf=(_pivot->left->left->height)-(_pivot->left->right->height);
        }
        else if(_pivot->left->left==NULL&&_pivot->left->right==NULL){
            bfbf=0;
        }
        else if(_pivot->left->left!=NULL||_pivot->left->right!=NULL){
            _pivot->left->left!=NULL?bfbf=(_pivot->left->left->height)+1:bfbf=-(_pivot->left->right->height)-1;
        }
        if(bfbf==1){
            _LL_rotation(_pivot);
        }
        else{
            _RR_rotation(_pivot->left);
            _LL_rotation(_pivot);
        }
    }
    else if(_pivot_bf==-2){
        int bfbf;
        if(_pivot->right->left!=NULL&&_pivot->right->right!=NULL){
            bfbf=(_pivot->right->left->height)-(_pivot->right->right->height);
        }
        else if(_pivot->right->left==NULL&&_pivot->right->right==NULL){
            bfbf=0;
        }
        else if(_pivot->right->left!=NULL||_pivot->right->right!=NULL){
            _pivot->right->left!=NULL?bfbf=(_pivot->right->left->height)+1:bfbf=-(_pivot->right->right->height)-1;
        }
        if(bfbf==-1){
            _RR_rotation(_pivot);
        }
        else{
            _LL_rotation(_pivot->right);
            _RR_rotation(_pivot);
        }
    }
    return 0;
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int AVLTree::deletion(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    if (_root==NULL){
        return -1;
    }
    else{
        _searchExist(_root,key);
        if(_existance){
            _deleting(key);
            _existance=false;
        }
        else{
            return -1;
        }
    }
    _pivot_bf=0;
    _marking_height(_root);
    _checking_bf(_root);
    if(_pivot_bf==2){
        int bfbf;
        if(_pivot->left->left!=NULL&&_pivot->left->right!=NULL){
            bfbf=(_pivot->left->left->height)-(_pivot->left->right->height);
        }
        else if(_pivot->left->left==NULL&&_pivot->left->right==NULL){
            bfbf=0;
        }
        else if(_pivot->left->left!=NULL||_pivot->left->right!=NULL){
            _pivot->left->left!=NULL?bfbf=(_pivot->left->left->height)+1:bfbf=-(_pivot->left->right->height)-1;
        }

        if(bfbf==1){
            _LL_rotation(_pivot);
        }
        else{
            _RR_rotation(_pivot->left);
            _LL_rotation(_pivot);
        }
    }
    else if(_pivot_bf==-2){
        int bfbf;
        if(_pivot->right->left!=NULL&&_pivot->right->right!=NULL){
            bfbf=(_pivot->right->left->height)-(_pivot->right->right->height);
        }
        else if(_pivot->right->left==NULL&&_pivot->right->right==NULL){
            bfbf=0;
        }
        else if(_pivot->right->left!=NULL||_pivot->right->right!=NULL){
            _pivot->right->left!=NULL?bfbf=(_pivot->right->left->height)+1:bfbf=-(_pivot->right->right->height)-1;
        }
        if(bfbf==-1){
            _RR_rotation(_pivot);
        }
        else{
            _LL_rotation(_pivot->right);
            _RR_rotation(_pivot);
        }
    }
    return 0;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

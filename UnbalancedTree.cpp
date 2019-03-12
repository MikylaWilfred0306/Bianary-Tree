#include "UnbalancedTree.h"
#include <iostream>

using namespace std;


//Constructor
//Average and Worst Case is 1 data allocation
template<typename T>
 UnbalancedTree<T>::UnbalancedTree(){
    root = nullptr;
 }

//Destructor
//Average and Worst Case is 1 function call
template<typename T>
UnbalancedTree<T>::~UnbalancedTree(){
    if (root != nullptr){
       destroyThemAll(root);
    }
    else return;
}

//Recursivly iterates through tree to delete
//Average Case 2 function calls
//Worst Case 2 function calls
template<typename T>
void UnbalancedTree<T>::destroyThemAll(Node <T>* node){
    if(node == nullptr){
        return;
    }
    if(node->left){
        destroyThemAll(node->left);
    }
    if(node->right){
        destroyThemAll(node->right);
    }

    delete node;
}

//Copy Tree in Constructor form
//Average Case 1 data allocation, 1 dara initialization and 1 function call
//Worst Case 1 data allocation, 1 dara initialization and 2 function call
template<typename T>
UnbalancedTree<T>::UnbalancedTree(const UnbalancedTree<T> &tree){
    Node<T>* current;
    if(tree.root->data){
      current->data = tree.root->data;
    } else {
        return;
    }
    root = current;
    if(tree.root->left){
        setSame(root->left, tree.root->left, root, 1);
    }
    if(tree.root->right){
         setSame(root->right, tree.root->right, root, 2);
    }
}

//Recursivly iterates through tree to recreate
//Average Case N-1 function calls and 1 data allocation, 1 initializations
//Worst Case N-1 function calls and 1 data allocation, 1 initializations
template<typename T>
void UnbalancedTree<T>::setSame(Node <T>* newTree, Node <T>* current, Node <T>* newTreeParent, int location){
    if(current == nullptr){
        return;
    }
    newTree->data = current->data;
    newTree->parent = newTreeParent;

    if (location == 2){
         newTreeParent->right = newTree;
    }
     if (location == 1){
         newTreeParent->left = newTree;
    }

    setSame(newTree->left, current->left,  newTree, 1);
    setSame(newTree->right, current->right, newTree, 2);
}

//Recursivly iterates through tree to recreate
//Average Case N-1 function calls and 1 data allocation, 1 initializations
//Worst Case N-1 function calls and 1 data allocation, 1 initializations
template<typename T>
void UnbalancedTree<T>::setSame(Node <T>* current, Node <T>* newTreeParent, int location){
    if(current == nullptr){
        return;
    }
    Node <T>* newTreeNode = new Node<T>();
    newTreeNode->data = current->data;
    newTreeNode->parent = newTreeParent;

    if (location == 2){
         newTreeParent->right = newTreeNode;
    }
     if (location == 1){
         newTreeParent->left = newTreeNode;
    }

    setSame(current->left,  newTreeNode, 1);
    setSame(current->right, newTreeNode, 2);
}

//Copy Tree Using Equal Sign
//Average Case 1 function calls and 1 data allocation, 1 data initialization
//Worst Case 1 function calls and 1 data allocation, 2 data initialization
template<typename T>
UnbalancedTree<T>& UnbalancedTree<T>::operator=(const UnbalancedTree<T> &tree){
    UnbalancedTree<T> newTree;
    Node<T>* current = new Node<T>();
    if(tree.root){
        current->data = tree.root->data;
    }
    newTree.root = current;
     if(tree.root->left){
        setSame(tree.root->left, newTree.root, 1);
    }
    if(tree.root->right){
         setSame(tree.root->right, newTree.root, 2);
    }
     return newTree;
}


//Average Case would be 1 data allocation and n/2(average height) initialization.
//Worst Case would be 1 data allocation and n (height) initionalizations.
template<typename T>
Node<T>* UnbalancedTree<T>::finder(Node <T>* node){
   Node<T>* current = root;
    while (current != nullptr){
        if (current->data == node->data){
            return current;
        }else if (current->data > node->data){
            current = current->left;
        }
        else {
            current = current->right;
        }
   }

   return nullptr;

}

//Average Case is 1 data allocation and 2 + n/2 (average height) data initionalizations
//Worst Case is 1 data allocation and 2 + n (full height) data initionalizations
template<typename T>
void UnbalancedTree<T>::inserter(Node <T>* node){
  if (!root) {
    root = node;
    return;
  }

  Node<T> *current = root;
  while (true) {
    if (node->data < current->data) {
      if (current->left) {
        current = current->left;
      } else {
        current->left = node;
        node->parent = current->left;
        break;
      }
    } else {
      if (current->right) {
        current = current->right;
      } else {
        current->right = node;
        node->parent = current->right;
        break;
      }
    }
  }
}


//Average case is 3 data allocations and 4 data intitialization.
//Worst Case is 3 data allocations and n (height) times 3 + 1 data initializatoin.
template<typename T>
void UnbalancedTree<T>::eraser(Node <T>* node){
 Node<T>* parental = node->parent;
 Node<T>* successor = nullptr;
    if (node->left != nullptr && node->right != nullptr ){
             Node<T>* current = node->right;
           while (current != nullptr){
                successor = current;
                current = current->left;
           }

           node->data = successor->data;
           eraser(successor);
            return;
    }else if (node->left != nullptr || node->right != nullptr){
         Node<T>* child = nullptr;
        if (node->left != nullptr){
            child = node->left;
            child->parent = parental;
            if (parental != nullptr){
                parental->left = child;
            }else{
                root = child;
            }
        }else{
            child = node->right;
            child->parent = parental;
            if (parental != nullptr){
                parental->right = child;
            }else{
                root = child;
            }
        }
    }else{
        if (parental->left == node){
            parental->left = nullptr;
        }else{
            parental->right = nullptr;
        }
    }
    if (node == root && node->left == nullptr && node->right == nullptr){
        root = nullptr;
    }
    delete node;
}


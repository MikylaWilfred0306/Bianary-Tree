#include "AVLTree.h"

using namespace std;

//Average and Worst Case is 1 data allocation
template<typename T>
AVLTree<T>::AVLTree()
{
   AVL = new UnbalancedTree<T>();
}


//Destructor
//Average and Worst Case is 1 function call
template<typename T>
AVLTree<T>::~AVLTree(){
     if (AVL->root != nullptr){
       AVL->destroyThemAll(AVL->root);
    }
    else return;
}


//Copy Tree in Constructor form
//Average and Worst Case is one operator call
template<typename T>
AVLTree<T>::AVLTree(const AVLTree<T> &tree){
    AVL = tree.AVL;
}


//Copy Tree Using Equal Sign
//Average and Worst Case is one operator call
template<typename T>
AVLTree<T>& AVLTree<T>::operator=(const AVLTree<T> &tree){
    AVL = tree.AVL;
}


//Average and Worst Case would be 1 data allocation and log2N (height) initionalizations.
template<typename T>
Node<T>* AVLTree<T>::finder(Node <T>* node){
    AVL->finder(node);
}

//Average and Worst Case is 1 data allocation and 2 + log2N (full height) data initionalizations
template<typename T>
void AVLTree<T>::inserter(Node <T>* node){
    AVL->inserter(node);
    balancingAct(node);
}


//Average case is 3 data allocations and 4 data intitialization.
//Worst Case is 3 data allocations and log2N (height) times 3 + 1 data initializatoin.
template<typename T>
void AVLTree<T>::eraser(Node <T>* node){
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
                AVL->root = child;
            }
        }else{
            child = node->right;
            child->parent = parental;
            if (parental != nullptr){
                parental->right = child;
            }else{
                AVL->root = child;
            }
        }
    }else{
        if (parental->left == node){
            parental->left = nullptr;
        }else{
            parental->right = nullptr;
        }
    }
    if (node == AVL->root && node->left == nullptr && node->right == nullptr){
        AVL->root = nullptr;
    }
   balancingAct(node);
   node = nullptr;
}


//Average and Worst Case is log2N (height), 3 function calls, 1 operator call, and 3 data allocations
template<typename T>
void AVLTree<T>::balancingAct(Node <T>* node){
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    int balanceFactor = leftHeight - rightHeight;
    if (balanceFactor > 1)
    {
        if (leftHeight > 0)
            leftLeftRotation(node);
        else
            leftRightRotation(node);
    }
    else if (balanceFactor < -1)
    {
        if (rightHeight > 0)
            rightLeftRotation(node);
        else
            rightRightRotation(node);
    }
    return;

}

//Average and Worst Case 4 data allocations, 2 fuction calls, 5 initializations and 1 operator
template<typename T>
int AVLTree<T>::height(Node<T> *node)
{
    int totalHeight = 0;
    if (node != nullptr)
    {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        int newHeight = (leftHeight<rightHeight)?rightHeight:leftHeight;
        totalHeight = newHeight + 1;
    }
    return totalHeight;
}

//Average and Worst Case 1 data allocation and 5 initializations
 template<typename T>
Node<T>* AVLTree<T>::rightRightRotation(Node<T>* parental)
{
    Node<T> *node;
    node = parental->right;
    parental->right = node->left;
    node->left = parental;
    node->parent = parental->parent;
    parental->parent = node;
    return node;
}
//Average and Worst Case 1 data allocation and 5 initializations
template<typename T>
Node<T>* AVLTree<T>::leftLeftRotation(Node<T>* parental)
{
    Node<T> *node;
    node = parental->left;
    parental->left = node->right;
    node->right = parental;
    node->parent = parental->parent;
    parental->parent = node;
    return node;
}
//Average and Worst Case 1 data allocation, 1 function call and 2 initializations
template<typename T>
Node<T>* AVLTree<T>::leftRightRotation(Node<T>* parental)
{
    Node<T> *node;
    node = parental->left;
    parental->left = rightRightRotation(node);
    return leftLeftRotation(parental);
}

//Average and Worst Case 1 data allocation, 1 function call and 2 initializations
template<typename T>
Node<T>* AVLTree<T>::rightLeftRotation(Node<T>* parental)
{
    Node<T> *node;
    node = parental->right;
    parental->right = leftLeftRotation(node);
    return rightRightRotation(parental);
}

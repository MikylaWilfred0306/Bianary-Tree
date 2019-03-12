#ifndef AVLTREE_H
#define AVLTREE_H
#include "UnbalancedTree.h"

using namespace std;

template<typename T>
class AVLTree
{   private:
     UnbalancedTree<T>* AVL;
     void balancingAct(Node <T>* node);
     int height(Node<T> *node);
     Node<T>* rightRightRotation(Node<T>* parental);
     Node<T>* leftLeftRotation(Node<T>* parental);
     Node<T>* leftRightRotation(Node<T>* parental);
     Node<T>* rightLeftRotation(Node<T>* parental);
    public:
      AVLTree();
      ~AVLTree();
      AVLTree(const AVLTree<T> &tree);
      AVLTree<T>& operator=(const AVLTree<T> &tree);
      Node<T>* finder(Node <T>* node);
      void inserter(Node <T>* node);
      void eraser(Node <T>* node);
};

#endif

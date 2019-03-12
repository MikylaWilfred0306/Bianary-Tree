#ifndef UNBALANCEDTREE_H
#define UNBALANCEDTREE_H
#include "node.h"

template<typename T>
class UnbalancedTree{
    public:
      UnbalancedTree();
      ~UnbalancedTree();
      UnbalancedTree(const UnbalancedTree<T> &tree);
      UnbalancedTree<T>& operator=(const UnbalancedTree<T> &tree);
      Node<T>* finder(Node <T>* node);
      void inserter(Node <T>* node);
      void eraser(Node <T>* node);
      void destroyThemAll(Node <T>* node);
      Node<T> *root;
      void setSame(Node <T>* newTree, Node <T>* current, Node <T>* newTreeParent, int location);
      void setSame(Node <T>* current, Node <T>* newTreeParent, int location);
};


#endif

#include "UnbalancedTree.h"
#include "UnbalancedTree.cpp"
#include "AVLTree.h"
#include "AVLTree.cpp"
#include <iostream>


int main()
{
   UnbalancedTree<int> test;
    Node<int>* temp = new Node<int>();
    temp->data = 420;
    test.inserter(temp);
    Node<int>* whee = new Node<int>();
    whee->data = 42;
    test.inserter(whee);
    Node<int>* blah = new Node<int>();
    blah->data = 4200;
    test.inserter(blah);
    test.finder(temp);
    test.eraser(temp);
    UnbalancedTree<int> test1(test);
    Node<int>* me = new Node<int>();
    me->data = 420;
    test1.inserter(me);
    test1.finder(me);
    UnbalancedTree<int> test2;
    test2 = test;

    AVLTree<bool> test3;
    Node<bool>* bolls = new Node<bool>();
    bolls->data = true;
    test3.inserter(bolls);
    Node<bool>* joey = new Node<bool>();
    joey->data = false;
    test3.inserter(joey);
    Node<bool>* yugi = new Node<bool>();
    yugi->data = false;
    test3.inserter(yugi);
    test3.finder(joey);
    test3.eraser(yugi);
    AVLTree<bool> test4;
    test4 = test3;
    AVLTree<bool> test5(test3);
    return 0;
}


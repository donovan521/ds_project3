#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <string>
#include "node.h"

using namespace std;

class binaryTree {
    public:
    int numNodes = 0; // or just make method?
    Node * root;

    /**
    * "Default" Constructor
    */
    binaryTree();


    /**
    * Constructors
    */
    binaryTree(Node * r);

    /**
    * copy constructor
    */
    binaryTree(const binaryTree &);

    /**
    * copy operator
    */
    binaryTree & operator = (const binaryTree &);

    /**
    * Destructor
    */
    //~Node(void);

    
    void Delete(Node * z);
    //insert function
    void Insert(Node *);

};

#endif //_binaryTree_H

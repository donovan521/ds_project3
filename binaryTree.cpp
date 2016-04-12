#include <string>
#include <iostream>
#include "node.h"
#include "binaryTree.h"

using namespace std;



/**
 * Constructors
 */
binaryTree::binaryTree(){
    root = nullptr;
}

binaryTree::binaryTree(Node * r){
    root = r;
    numNodes++;
}


/**
 * copy constructor
 */
binaryTree::binaryTree(const binaryTree & m){
  this->root = m.root;
}

/**
 * copy operator
 */

  binaryTree& binaryTree::operator = (const binaryTree & m){
      this->root = m.root;

      return *this;
}



void binaryTree::Delete(Node * z){
  
}

void binaryTree::Insert(Node * n){
    
  }


/**
 * Destructor
 */
//Order::~Order(void){

//}

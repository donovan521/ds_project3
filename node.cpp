#include <string>
#include <iostream>
#include "node.h"



using namespace std;



/**
 * Constructors
 */
Node::Node(const int val){
    value = val;
    parent = nullptr;
    leftChild = nullptr;
    rightChild = nullptr;
}


Node::Node(const int val, Node * lChild, Node * rChild, Node * p){
    value = val;
    leftChild = lChild;
    rightChild = rChild;
    parent = p;
}

/**
 * copy constructor
 */
Node::Node(const Node & m){
  this->value = m.value;
  this->leftChild = m.leftChild;
  this->rightChild = m.rightChild;
  this->parent = m.parent;
}

/**
 * copy operator
 */
 
  Node& Node::operator = (const Node & m){
      this->value = m.value;
      this->leftChild = m.leftChild;
      this->rightChild = m.rightChild;
      this->parent = m.parent;
  
      return *this;
}

/**
 * Destructor
 */
//Order::~Order(void){

//}

  bool Node::isLeaf() {
      if ((this->leftChild == nullptr) && (this->rightChild ==  nullptr)) {
          return true;
      }
      else {
      return false;
      }

  }

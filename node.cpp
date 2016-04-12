#include <string>
#include <iostream>
#include "node.h"



using namespace std;



/**
 * Constructors
 */
Node::Node(const int val, const char c){
    frequency = val;
    character = c;
    parent = nullptr;
    leftChild = nullptr;
    rightChild = nullptr;
}


Node::Node(const int val,const char c, Node * lChild, Node * rChild, Node * p){
    frequency = val;
    character = c;
    leftChild = lChild;
    rightChild = rChild;
    parent = p;
}

/**
 * copy constructor
 */
Node::Node(const Node & m){
  this->frequency = m.frequency;
  this->character = m.character;
  this->leftChild = m.leftChild;
  this->rightChild = m.rightChild;
  this->parent = m.parent;
}

/**
 * copy operator
 */
 
  Node& Node::operator = (const Node & m){
      this->frequency = m.frequency;
      this->character = m.character;
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

#ifndef _NODE_H
#define _NODE_H 
 
#include <string>
using namespace std;

class Node {
	public:
    int frequency;
    char character;
    Node * leftChild;
    Node * rightChild;
    Node * parent;

	/**
    * Default Constructor
    */
    Node() = default;

	
	/**
    * Constructors
	*/
    Node(const int val, const char c);

    Node(const int val,const char c, Node * lChild, Node * rChild, Node * p);
	
	/**
	* copy constructor
	*/
	Node(const Node &);
	
	/**
	* copy operator
	*/
	Node & operator = (const Node &);

    //isleaf
    bool isLeaf();
	
	/**
	* Destructor
	*/
	//~Node(void);
};

#endif //_NODE_H

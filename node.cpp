//node.cpp
//implementation for the Node class

#include "node.h"
#include <iostream>

//default constructor
Node::Node(){
    value = -1;
    left = NULL;
    right = NULL;
}

//constructor
Node::Node(int val){
    value = val;
    left = NULL;
    right = NULL;
}

//destructor
Node::~Node(){

}
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <iostream>
#include <string>

using namespace std;
// TODO your code goes here:
template<typename T>
class LinkedList{
private:
int count;
Node<T> *head;
Node<T> *tail;
public:

LinkedList()
    : count(0),head(nullptr),tail(nullptr){
}

void push_front(const T &ele){
  Node<T> *newNode = new Node<T>(ele);
  if(count>0){
    newNode->next = head;
    head->previous = newNode;
  }else{
    tail = newNode;
  }
  head = newNode;
  ++count;

}

T & front(){
  return head->data;

}

void push_back(const T &ele){
  Node<T> *newNode = new Node<T>(ele);
  if(count>0){
    tail->next = newNode;
  }else{
    head = newNode;
  }
  tail = newNode;
  ++count;

}

T & back(){
  return tail->data;

}

int size() const{
  return count;
}

 NodeIterator<T> begin(){
   NodeIterator<T> s(head);
  return s;
}

NodeIterator<T> end(){
  NodeIterator<T> s(tail->next);
  return s;
}

~LinkedList(){
  Node<T> *current = head;
  while( current != nullptr ) {
    Node<T> *next = current->next;
    delete current;
    current = next;
  }
  head = nullptr;
}


};
// do not edit below this line

#endif

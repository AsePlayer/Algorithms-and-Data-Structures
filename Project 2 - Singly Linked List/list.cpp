#include <iostream>
#include "node.cpp"
using namespace std;
template<class T>
  
  class list{
  private:
  struct node* newnode = new node;
  T val;
  int sizeOfList;
  public:
  list(){
  }
  //inserts new node sequentially.
  void insert(T value){
    val = value;
    newnode->insertSequential(val);
    sizeOfList++;
  }
  
  void display(){
    newnode->display();
  }
  
  bool empty(){
    return(sizeOfList == 0 ? true : false);
  }

  //Pops first node
  void pop_front(){
    newnode->deletenode(0);
    sizeOfList--;
  }
  //Pops last node
  void pop_back(){
    newnode->deletenode(sizeOfList-1);
    sizeOfList--;
  }
  //Gets data of first node
  T front(){
    return newnode->head->data;
  }
  //Gets data of last node
  T back(){
    struct node* temp = newnode->head;
    while(temp->next != NULL){
      temp = temp->next;
    }
    return temp->data;
  }
  //Taking advantage of "first in last out" aspect of the linked list, I populate a new list by looping through the old list and inserting to the front of the new one to get a reversed list.
  void reverse(){
    struct node* temp = newnode->head;                     
    struct node* tempReverse = new node;     
    
    while(temp != NULL){
      tempReverse->insertFront(temp->data);
      temp = temp->next;
    }
    newnode = tempReverse;
  
  }
  //Loops through list I wish to merge, inserting each node sequentially into old list.
  void merge(const list<T> &newList){
    struct node* mergeThis = newList.newnode->head;

    struct node* temp = mergeThis;  
    while(temp != NULL){
      insert(temp->data);
      temp = temp->next;
    }

  }

  //Don't let this function decieve you, it is quite powerful at returning the size of the list
  int size(){
    return sizeOfList;
  }

  };

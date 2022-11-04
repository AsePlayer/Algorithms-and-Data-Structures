//Lydia K Fritz
//2/14/2019
//Provided C++ DLinkedList

#pragma once

#ifndef DLINKLIST_H
#define DLINKLIST_H

#include <iostream>

using namespace std;

template <class T>
class DLinkedList {

	//PROVIDED
	friend ostream & operator<<(ostream & out, const DLinkedList<T> & rhs) {
		DNode * curr = rhs.header->next;
		while (curr != rhs.header) {
			out << curr->data << " ";
			curr = curr->next;
		}
		return out;
	}

public:

	//inner class DNode PROVIDED
	class DNode {
	public:
		DNode * next;
		DNode * prev;
		T data;

		DNode(T val = T()) {
			data = val;
			next = prev = this;
		}
		
	};

	//create an empty list:  PROVIDED
	DLinkedList() {
		//create the header
		header = new DNode();		
	}

	//add method  PROVIDED
	DNode * add(T item) {
		//add a new node and return a 
		//pointer to this node
		DNode * newNode = new DNode(item);
		newNode->prev = header;
		newNode->next = header->next;
		header->next->prev = newNode;
		header->next = newNode;
		return newNode;
	}

	/**
	* ASSIGNED
	* remove val from the list
	*
	* @param val
	* @return true if successful, false otherwise
	*/
	bool remove(T val) {

    DNode * tempNode = header;

    while(tempNode != NULL){
      
      if(tempNode->data == val){
        if(tempNode->prev == NULL){
          header = tempNode->next;
          header->prev = NULL;
        }
        else if(tempNode->next == NULL){
          tempNode->prev->next = NULL;
        }
        else{
          cout << "Removing " << tempNode->data << endl;
          tempNode->next->prev = tempNode->prev;
          tempNode->prev->next = tempNode->next;
        }
        delete(tempNode);
        return true;
      }
      tempNode = tempNode->next;
    }
    cout << val << " not here" << endl;
    return false;
    

		return true;
	}
	

	/**
	* ASSIGNED
	*
	* @param item
	*/
void insertOrder(T item) {
	DNode* newDNode = new DNode(item);                              // new node containing the new data
	DNode* temp = header->next;                                     // temp header node

	while (temp->data <= newDNode->data && temp != header) 
  { 
    temp = temp->next; 
  }    // loop to know where to insert the new data

	if (temp->next == header && temp->data <= newDNode->data) {      // checks if the data is less than the final node
		newDNode->next = temp->next;                                // inserts node before the last value
		newDNode->prev = temp;

		temp->next->prev = newDNode;
		temp->next = newDNode;
	}
	else if (temp == header && temp->data >= newDNode->data) {     // checks if the data is greater than the final node
		newDNode->next = temp;                                      // inserts node after the last value
		newDNode->prev = temp->prev;

		temp->prev->next = newDNode;
		temp->prev = newDNode;
		header = newDNode;                                          // reassign header node
	}
	else {                                                        // inserts node for all other cases
		newDNode->next = temp;
		newDNode->prev = temp->prev;

		temp->prev->next = newDNode;
		temp->prev = newDNode;
    
	}
}

	/**
	* ASSIGNED
	*
	* @param item
	*/
	bool insertOrderUnique(T item) {
      
    DNode* newDNode = new DNode(item);                              // new node containing the new data
    DNode* temp = header->next;                                     // temp header node

    while (temp->data < newDNode->data && temp != header) 
    { 
      temp = temp->next; 
    }    // loop to know where to insert the new data

    if (temp->next == header && temp->data < newDNode->data) {      // checks if the data is less than the final node
      newDNode->next = temp->next;                                // inserts node before the last value
      newDNode->prev = temp;

      temp->next->prev = newDNode;
      temp->next = newDNode;
    }
    else if (temp == header && temp->data > newDNode->data) {     // checks if the data is greater than the final node
      newDNode->next = temp;                                      // inserts node after the last value
      newDNode->prev = temp->prev;

      temp->prev->next = newDNode;
      temp->prev = newDNode;
      header = newDNode;                                          // reassign header node
      
    }
    else {                                                        // inserts node for all other cases
      if(temp->data == newDNode->data){
        return false;
      }
      
      newDNode->next = temp;
      newDNode->prev = temp->prev;

      temp->prev->next = newDNode;
      temp->prev = newDNode;
      
    }
    

		return true;
	}

	/**
	* ASSIGNED
	* PRE:  this and rhs are sorted lists
	* @param rhs
	* @return list that contains this and rhs merged into a sorted list
	* POST:  returned list will not contain duplicates, both rhs and this
	* will have no elements
	*/
	DLinkedList merge(DLinkedList rhs) {
		DNode* temp = header;
    DLinkedList result;

    while(temp->next != header){
      temp->prev = temp;
      temp = temp->next;
      result.insertOrderUnique(temp->data);
    }
    temp = rhs.header;
    while(temp->next != rhs.header){
      temp->prev = temp;
      temp = temp->next;
      result.insertOrderUnique(temp->data);
      //cout << temp->data;
    }
    rhs.header = NULL;
    delete(temp);

		return result;
	}

	
private:
	//DLinkedList fields:  PROVIDED
	DNode * header;	

};


#endif
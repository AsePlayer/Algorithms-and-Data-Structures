#include <iostream>
using namespace std;


struct node {
  public:
  
  int data;
  node* next;
  node* head = NULL;
  node* temp = NULL;

  void insertFront(int newData){        //a method to insert to the front
    struct node* newnode = new node;    //this allocates memory for our node
    newnode->data = newData;            //access the data member of newnode
    newnode->next = head;               //take the next pointer and point to head
    head = newnode;                     //now we make the swap
  }

  void insertSequential(int newData){
    struct node* newnode = new node;    //building our node
    struct node* temp = head;           //temp node
    struct node* previous = new node;   //previous node -> we can only go one way
    int counter = 0;
    newnode->data = newData;            //adding to member data
    while(temp != NULL && temp->data < newData){
      previous = temp;                  //swapping positions so we can access the pointers
      temp = temp->next;                //moving the temp node
      counter++;
    }
    //Deals with inserting to very front of list if number is the lowest.
    if(counter == 0){
      insertFront(newData);
    }
    else{
      insertPos(counter, newData);
    }

  }

  void insertBack(int newData){         //pass in the data you want
    struct node* newnode = new node;    //build a node
    struct node* temp = head;           //build a temp node
    newnode->data = newData;            //add to data member
    newnode->next = NULL;               //make next NULL
    while(temp->next != NULL){
      temp = temp->next;                //go to the end of the list
    }
    temp->next = newnode;               //make that spot point to Newnode
  }

  void insertPos(int pos, int newData){ //getting position and the data
    struct node* newnode = new node;    //building our node
    struct node* temp = head;           //temp node
    struct node* previous = new node;   //previous node -> we can only go one way
    int position = pos;                 //where our loop will stop
    newnode->data = newData;            //adding to member data
    for(int i = 0; i < position; i++){
      previous = temp;                  //swapping positions so we can access the pointers
      temp = temp->next;                //moving the temp node
    }
    previous->next = newnode;           //setting the data in the list
    newnode->next = temp;               //pointing to next node
  }

  void deletenode(int pos){             //sending in the pos to discriminate against
    struct node* temp = head;           //building a temp node = head
    struct node* previous = new node;   //need a previous node to keep link
    if(pos == 0){
      head = temp->next;                //deleting the head
    }
    while(pos > 0){
      pos--;
      previous = temp;                  //deleting from inside the list
      temp = temp->next;
    }
    previous->next = temp->next;        //deleting the tail
    delete(temp);
    //temp and previous move together, this way we can grab previous and use the pointer
  }

  void display(){
    struct node* temp;                  //create temporary node to not mess with head
    temp = head;                        
    while(temp != NULL){                //loops until the NULL node (end of list)
      cout << temp->data << " ";        //access data member and cout
      temp = temp->next;                //advance the node
    }
    cout << endl;
  }
};
#include <iostream>
#include <fstream>
using namespace std;

//making a constant size for the array
const int SIZE = 31;
//this is my hash key
const int HASH = 31;

//creating a struct node for the linked list
struct node{
  int data;
  node* next = NULL;
};
//a global array called bucketArray
struct node* bucketArray[SIZE];

//linked list insert method
void insert(int newData){
  //create a new node
  struct node* newNode = new node;
  newNode -> data = newData;
  newNode -> next = bucketArray[newData % HASH];
  bucketArray[newData % HASH] = newNode;
}

//As a wise man once told me, there is a lot going on with the find. We pass in what we are looking for
bool find(int lookup){
  cout << "Word";
  int counter = 0;

  struct node* temp;
  int x = lookup % HASH;
  temp = bucketArray[x];
  //If null empty
  if(bucketArray[x] == NULL){
    counter++;
    cout << " not found. ";
    cout << "Searched " << counter << " elements." << endl;
    return false;
  }
  //we need to check if the data may be in that index, but in the chain so we need to step through the list
  else{
    while(temp != NULL){
      counter++;
      if(temp -> data == lookup){
        cout << " found at index " << x << ". Searched " << counter << " elements." << endl;
        return true;
      }
      //moves the while loop to the end of the list
      temp = temp -> next;
    }
    cout << " not found. ";
    cout << "Searched " << counter << " elements." << endl;
    return false;
  }
}

void display(){
  struct node* temp;
  for(int i = 0; i < SIZE; i++){
    int x = i % HASH;
    temp = bucketArray[x];
    while(temp != NULL){
      cout << temp -> data << " ";
      temp = temp -> next;
    }
    cout << endl;
  }
}

int hashDat(string str){
  // P and M    
  int p = 31;    
  int m = 1e9 + 9;    
  long long power_of_p = 1;    
  long long hash_val = 0;    
  // Loop to calculate the hash value    
  // by iterating over the elements of string    
  for (int i = 0; i < str.length(); i++) {
    hash_val = (hash_val + (str[i] - 'a' + 1) * power_of_p) % m;        
    power_of_p = (power_of_p * p) % m;
  }    
  return hash_val;
}

int main(){
  ifstream fin("text.txt");
	string str;
  
  fin >> str;
  cout << str << " ";
  insert(hashDat(str));

	while (fin>>str) {
    cout << str << " ";
    insert(hashDat(str));
	}
  cout << endl;
	fin.close();
  string search;

  // Search the hash table for Gangnam Style lyrics! (CASE SENSITIVE)
  while(true){
    cout << endl << "What are ya lookin' for?" << endl;
    cin >> search;
    find(hashDat(search));
  }
}
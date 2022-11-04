#include <iostream>
#include "list.cpp"
using namespace std;

int main() {

  list<int> listy;

  cout << endl << "Inserting numbers 1, 3, 2, 1 into list test..." << endl;  
  listy.insert(1);
  listy.insert(3);
  listy.insert(2);
  listy.insert(1);
  
  cout << "List: ";
  listy.display();

  cout << endl << "Copy Constructor test..." << endl;
  list<int>lister(listy);
  cout << "List: ";
  lister.display();

  cout << endl << "Accessing first element test..." << endl;
  cout << "First: " << lister.front() << endl;

  cout << endl << "Accessing last element test..." << endl;
  cout << "Last: " << lister.back() << endl;

  cout << endl << "Removing value at front test..." << endl;
  cout << "Before: ";
  lister.display();
  lister.pop_front();
  cout << "After: ";
  lister.display();

  cout << endl << "Removing value at back test..." << endl;
  cout << "Before: ";
  lister.display();
  lister.pop_back();
  cout << "After: ";
  lister.display();

  cout << endl << "Checking if populated list is empty test... (0 = no, 1 = yes)" << endl;
  cout << "List: ";
  lister.display();
  cout << "Empty: " << lister.empty() << endl;

  list<int> emptyList;
  cout << endl << "Checking if empty list is empty test... (0 = no, 1 = yes)" << endl;
  cout << "List: ";
  emptyList.display();
  cout << "Empty: " << emptyList.empty() << endl;

  cout << endl << "Checking size of list test..." << endl;
  cout << "List: ";
  lister.display();
  cout << "Size: " << lister.size() << endl;

  cout << endl << "Reversing list test..." << endl;
  lister.insert(1);
  lister.insert(3);
  cout << "List: ";
  lister.display();
  cout << "Reversed List: ";
  lister.reverse();
  lister.display();

  cout << endl << "Merging two lists test..." << endl;
  list<int> firstList;
  list<int> secondList;
  firstList.insert(11);
  firstList.insert(22);
  firstList.insert(33);
  secondList.insert(3);
  secondList.insert(2);
  secondList.insert(1);

  cout << "List 1: ";
  firstList.display();
  cout << "List 2: ";
  secondList.display();
  cout << endl;
  firstList.merge(secondList);
  cout << "List 1+2: ";
  firstList.display();

}
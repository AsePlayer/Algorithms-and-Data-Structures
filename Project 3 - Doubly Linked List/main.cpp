//Lydia K Fritz
//2/14/2019
//driver program for DLinkedList C++
//provided

#include "DLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string cleanUp(string str);

int main() {

	DLinkedList<string> lst1;
	DLinkedList<string> lst2;


	ifstream fin("Text1.in");

	string str;

	while (fin>>str) {		
		str = cleanUp(str);
		lst1.insertOrderUnique(str);
	}
	fin.close();

	fin.open("Text2.in");
	while (fin>>str) {
		str = cleanUp(str);
		lst2.insertOrderUnique(str);
	}

	cout << "List 1: " << lst1 << endl;
	cout << "List 2: " << lst2 << endl;
	

	//DLinkedList<string> combined = lst1.merge(lst2);

  //lst1.remove(5);

	cout << "\nAFTER MERGE" << endl;
	cout << "List 1: " << lst1 << endl;
	cout << "List 2: " << lst2 << endl;
	//cout << "\nCombined: " << combined << endl;

  cout << lst1.merge(lst2);

	return 0;
}

/**
* ASSIGNED
* @param str
* @return str in all lower case with LEADING and TRAILING non-alpha
* chars removed
*/
string cleanUp(string str) {
  int length = str.length();
  int counter = 0;
  
  for(int i = 0; i < length; i++){
    //Remove leading non-alpha char
    if(!isalpha(str[0])){
      str.erase(0);
    }
    //Turn uppercase chars to lowercase
    if(str[i] >= 65 && str[i] <= 92){
      str[i] = str[i]+32;
    }
    //Remove trailing non-alpha char
    if(!isalpha(str[length-1])){
      str.erase(0);
    }
  }

	return str;
}
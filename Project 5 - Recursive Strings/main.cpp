//Ryan Scott
//CST - 201 : Recursive Strings
//This file and project are my own work
//Requirements: https://docs.google.com/document/d/1nP-tVzcK50iPwNy1TXS2_DzRW4JL_qLU9I6RiDqmYgI/edit?usp=sharing

#include <iostream>
#include <fstream>
using namespace std;

/*
 * A Slip is a character string that has the following properties:
 * Its first character is either a 'D' or an 'E'
 * The first character is followed by a string of one or more 'F's
 * The string of one or more 'F's is followed by either a Slip or a 'G'
 * The Slip or 'G' that follows the F's ends the Slip. For example, DFFEFFFG is a Slip
 * since it has a 'D' for its first character, followed by a string of two F's, and ended by the Slip 'EFFFG'
 * Nothing else is a Slip
 */
bool isSlip(string str){
  //Checking for the bare minimum to form a Slip
  if((str[0] == 'D' || str[0] == 'E') && str[1] == 'F'){
    int counter = 1;
    //Increment through all the F's
    while(str[counter] == 'F'){
      counter++;
    }
    //Check for another slip or terminating G
    return (isSlip(str.substr(counter)) || (str[counter] == 'G' && counter == str.size() - 1));
  }
  return false;
}

/*
 * A Slap is a character string that has the following properties:
 * Its first character is an 'A'
 * If it is a two-character Slap then its second and last character is an 'H'
 * If it is not a two-character Slap, then it is in one of these two forms:
 * 'A' followed by 'B' followed by a Slap, followed by a 'C'
 * 'A' followed by a Slip (see above) followed by a 'C'
 * Nothing else is a Slap
 */
bool isSlap(string str){
  //Checking for the bare minimum to form a Slap
  if(str[0] == 'A' && str[1] == 'H'){
    return(str.length() == 2); 
  }
  else if(str[0] == 'A'){
    //if the index is found, it will be less than the size of str
    if(str[1] == 'B' && str.rfind('C') < str.size()){
      //Isolate and test for slap
      return (isSlap(str.substr(2, str.rfind('C') - 2)));
    }
    else{
      //Isolate and test for slip
      return (isSlip(str.substr(1, str.rfind('C') - 1)) && str.rfind('C') < str.size());
    }
  }
  return false;
}

/*
 * A Slop is a character string that consists of a Slap followed by a Slip
 */
bool isSlop(string str){
  int counter = 0;
  //Check for Slap bare minimum
  if(isSlap(str.substr(0,2))){
    counter += (str.substr(0,2)).length();
  }
  //Check for Slap normal
  else if(isSlap(str.substr(0, str.rfind('C') + 1))){
    counter += (str.substr(0, str.rfind('C') + 1)).length();
  }
  else{
    return false;
  }
  //Check for Slip after Slap.
  if(isSlip(str.substr(counter, str.rfind('G')))){
    return true;
  }
  return false;
}


int main() {
	ifstream text("stringFactory.txt");
	int numb;
  string str;

  text >> numb;
  cout << "SLIPS OUTPUT" << endl;
  for(int i = 0; i < numb; i++){
    text >> str;
    cout << ((isSlip(str)) ? "YES" : "NO") << endl;
  }
  cout << "END OF OUTPUT" << endl << endl;
  text.close();

  text.open("stringFactory.txt");
  text >> numb;
  cout << "SLAPS OUTPUT" << endl;
  for(int i = 0; i < numb; i++){
    text >> str;
    cout << ((isSlap(str)) ? "YES" : "NO") << endl;
  }
  cout << "END OF OUTPUT" << endl << endl;
  text.close();

  text.open("stringFactory.txt");
  cout << "SLOPS OUTPUT" << endl;
  for(int i = 0; i < numb; i++){
    text >> str;
    cout << ((isSlop(str)) ? "YES" : "NO") << endl;
  }
  cout << "END OF OUTPUT" << endl << endl;

}
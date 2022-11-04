#include <iostream>

using namespace std;

class MyString{
  private:
  int capacity = 10;
  char* words = NULL;
  int curr_length = 0;

  //Allocating memory with size needed for string.
  void ensureCapacity(){
    words = new char[capacity];
  }

  public:

  //Default Constructor
  MyString(){
    words = NULL;
    curr_length = 0;
  }

  //Constructor
  MyString(string user){
    //Determining required size of the array.
    while (user.length() > capacity){
      capacity *= 2;
    }
    
    ensureCapacity();

    for(int i = 0; i < user.length(); i++){
      words[i] = user[i];
      curr_length++;
    }

  }
  //Copy Constructor
  MyString(MyString &copy){
    while (copy.length() > capacity){
      capacity *= 2;
    }

    ensureCapacity();
    
    for(int i = 0; i < copy.length(); i++){
      words[i] = copy.words[i];
    }
    curr_length = copy.length();
  }

  void show(){
      cout << words << endl;
  }

  int length(){
    return curr_length;
  }
  
  //Operator overloads
  bool operator == (MyString strang) {
    //If lengths aren't the same, don't even bother comparing each character.
    if(curr_length != strang.length()){
      return (false);
    }
    for(int i = 0; i < curr_length; i++){
      if (words[i] != strang.words[i]){
        return (false);    
      }
    }
    return (true);
  }

  int operator < (MyString strang){
    int strangSize = strang.length();
    int smallerIndex = 0;
    
    if(curr_length > strangSize){
      smallerIndex = strangSize;
    }
    else{
      smallerIndex = curr_length;
    }
    //Checks for differences in letters at each index and compares them.
    for(int i = 0; i < smallerIndex; i++){
      if(strang.words[i] < words[i]){
        return -1;
      }
      else if(words[i] < strang.words[i]){
        return 1;
      }
    }
    //All letters are the same up to the smallest index, but bigger word still has letters.
    if(strang.length() < curr_length){
      return -1;
    }
    else if(curr_length < strang.length()){
      return 1;
    }
    //If it made it this far, they are the same word.
    else{
      return 0;
    }
  }

  int operator > (MyString strang){
    int strangSize = strang.length();
    int smallerIndex = 0;
    
    if(curr_length > strangSize){
      smallerIndex = strangSize;
    }
    else{
      smallerIndex = curr_length;
    }
    //Checks for differences in letters at each index and compares them.
    for(int i = 0; i < smallerIndex; i++){
      if(strang.words[i] > words[i]){
        return -1;
      }
      else if(words[i] > strang.words[i]){
        return 1;
      }
    }
    //All letters are the same up to the smallest index, but bigger word still has letters.
    if(strang.length() > curr_length){
      return -1;
    }
    else if(curr_length > strang.length()){
      return 1;
    }
    //If it made it this far, they are the same word.
    else{
      return 0;
    }
  }

  char operator [] (int index){
    char dontAccessMemoryThatDoesntBelongToYou;
    //Use the index to get the index!
    if (index < curr_length && index > -1){
      return(words[index]);
    }
    cout << "Index out of bounds." << endl;
    return dontAccessMemoryThatDoesntBelongToYou;
  }

  MyString operator + (MyString strang){
    //New array to encapsulate both MyStrings combining.
    char concatArray [curr_length + strang.length()];

    for(int i = 0; i < curr_length; i++){
      concatArray[i] = words[i];
    }
    for(int i = 0; i < strang.length(); i++){
      concatArray[i + curr_length] = strang.words[i]; 
    }
    //Adding a NULL terminator to prevent shenanigans.
    concatArray [curr_length+strang.length()] = 0;

    return MyString(concatArray);
  }

  MyString toUpper(){
    for(int i = 0; i < curr_length; i++){
      if(words[i]>=97 && words[i]<=122)
      {
		    words[i] = words[i]-32;
      }
    }
    return MyString(words);
  }

  MyString toLower(){
    for(int i = 0; i < curr_length; i++){
      if(words[i]>=65 && words[i]<=90)
      {
		    words[i] = words[i]+32;
      }
    }
    return MyString(words);
  }

  MyString substring(int num){
    MyString dontAccessMemoryThatDoesntBelongToYou;

    if (num < 0 || num > curr_length){
      cout << "Index out of bounds." << endl;
      return dontAccessMemoryThatDoesntBelongToYou;
    }
    else{
      char newArray [curr_length-num];
      for (int i = num; i < curr_length; i++){
        newArray[i-num] = words[i];
      }
      //Adding a NULL terminator to prevent shenanigans.
      newArray[curr_length-num] = 0;
      return MyString(newArray);
    }
  }

  MyString substring(int n, int m){
    MyString dontAccessMemoryThatDoesntBelongToYou;
    //For the love of god don't go out of bounds.
    if (n < 0 || m < 0 || n > m || n > curr_length || m > curr_length){
      cout << "Index out of bounds." << endl;
      return dontAccessMemoryThatDoesntBelongToYou;
    }
    else{
      char newArray [m-n];
      //Start at small index. Increment to big index. i-n to offset so array starts at 0.
      for (int i = n; i <= m; i++){
        newArray[i-n] = words[i];
      }
      //Adding a NULL terminator to prevent shenanigans.
      newArray[m-n] = 0;
      return MyString(newArray);
    }
  }

  int indexOf(MyString strang){
    int index;
    int compareCount = 0;
    
    for (int i = 0; i < curr_length; i++){
      //Store first match for the index for if they actually end up matching.
      if (words[i] == strang.words[0] && compareCount == 0){
        index = i;
      }

      //(i - index) because i should start at 0 for the substring we are comparing, regardless of index.
      //% strang.length() prevents the index of the substring from going out of bounds.
      if (words[i] == strang.words[(i - index) % strang.length()]){
        compareCount++;
      }
      else{
        //If one character doesn't match up, reset compareCount and index.
        index = -1;
        compareCount = 0;
      }
      //I compare compareCount to strang.length() to prevent using nested for loops to improve this algorithm's efficiency.
      if (compareCount == strang.length()){
        return index;
      }
    }

    return -1;
  }

  int lastIndexOf(MyString strang){
    int index;
    int compareCount = 0;
    int lastIndex = -1;
    
    for (int i = 0; i < curr_length; i++){
      //Store first match for the index for if they actually end up matching.
      if (words[i] == strang.words[0] && compareCount == 0){
        index = i;
      }

      //(i - index) because i should start at 0 for the substring we are comparing, regardless of index.
      //% strang.length() prevents the index of the substring from going out of bounds.
      if (words[i] == strang.words[(i - index) % strang.length()]){
        compareCount++;
      }
      else{
        //If one character doesn't match up, reset compareCount and index.
        index = -1;
        compareCount = 0;
      }
      //I compare compareCount to strang.length() to prevent using nested for loops.
      //Store latest match in latestIndex. If no match, -1 will return for fail
      if (compareCount == strang.length()){
        lastIndex = index;
        compareCount = 0;
      }
    }
    //Either return last match or there was never a match.
    return lastIndex;

  }

  //"The overloaded << operator function must then be declared as a friend of class Date so it can access the private data within a Date object." per https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-160
  friend ostream& operator << (ostream& os, const MyString& strang);

};


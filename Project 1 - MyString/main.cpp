#include <iostream>
#include "MyString.cpp"

using namespace std;

//Global override since we are also overriding ostream.
//https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-160
ostream& operator << (ostream& os, const MyString& strang){
  for(int i = 0; i < strang.curr_length; i++){
    os << strang.words[i];
  }
  return os;
}


int main() {
  
  cout << "Testing MyString: " << endl << "-----------------" << endl << endl;

  MyString s1 = MyString("Apple"); MyString s2 = MyString("Banana");
  cout << "s1 = MyString(\"Apple\") and s2 = MyString(\"Banana\")" << endl << endl;

  cout << "testing the << operator - cout << s2" << endl;
  cout << "s2 = " << "'" << s2 << "'" << endl << endl;

  cout << "testing copy constructor: - copying s1 to new MyString s3..." << endl;
  MyString s3 = MyString(s1);
  cout << "s1 = '" << s1 << "' and s3 = '" << s3 << "'" << endl << endl;

  cout << "testing the = operator - assigning s3 to s2..." << endl;
  s2 = s3;
  cout << "s2 = '" << s2 << "' and s3 = '" << s3 << "'" << endl << endl;

  cout << "testing .length() - finding length of s1..." << endl;
  cout << "there are " << s1.length() << " characters in '" << s1 << "'" << endl << endl; 

  cout << "testing < operator - does 'Apple' < 'Pineapple'?" << endl;
  int whosBigger = MyString("Apple") < MyString("Pineapple");
  string TorF;
  if(whosBigger == 1){
    TorF = "true";
  }
  else{
    TorF = "false";
  }
  cout << "'" << MyString("Apple") << "' < '" << MyString("Pineapple") << "' evaluates to " << whosBigger << " (" << TorF << ")" << endl << endl;

  cout << "testing < operator - does 'Apple' > 'Pineapple'?" << endl;
  whosBigger = MyString("Apple") > MyString("Pineapple");
  if(whosBigger == 1){
    TorF = "true";
  }
  else{
    TorF = "false";
  }
  cout << "'" << MyString("Apple") << "' > '" << MyString("Pineapple") << "' evaluates to " << whosBigger << " (" << TorF << ")" << endl << endl;

  cout << "testing out the == operator - comparing s1 to s1..." << endl;
  bool isSame = (s1 == s1);
  
  if(isSame){
    TorF = "true";  
  }
  else{
    TorF = "false";
  }
  cout << "'" << s1 << "' == '" << s1 << "' evaluates to " << isSame << " (" << TorF << ")" << endl << endl;
  cout << endl;
  
  
  s1 = MyString("I "); s2 = MyString("am "); s3 = MyString("a "); MyString s4 = MyString("sentence.");
  cout << "s1 = '" << s1 << "', s2 = '" << s2 << "', s3 = '" << s3 << "', s4 = '" << s4 << "'" << endl << endl;
  cout << "testing out the + operator - adding s1, s2, s3, and s4..." << endl;
  cout << "s1 + s2 + s3 + s4 = " << s1 + s2 + s3 + s4 << endl << endl;

  cout << "testing out .toLower() - turning s1 into all lowercase..." << endl;
  cout << "s1.toLower() = " << s1.toLower() << endl << endl;

  cout << "testing out .toUpper() - turning s1 + s2 + s3 + s4 into all uppercase..." << endl;
  cout << "(s1+s2+s3+s4).toUpper() = " << (s1+s2+s3+s4).toUpper() << endl << endl;


  cout << "testing out the [] operator - index 5 << 4 << 3 of s4..." << endl;
  cout << "s4[5] << s4[4] << s4[3] = " << s4[5] << s4[4] << s4[3] << endl << endl; 
  
  cout << "testing out .substring(int) - getting substring(7) of s4..." << endl;
  cout << "s4.substring(7) = " << s4.substring(7) << endl << endl;

  cout << "testing out .substring(int,int) - getting substring(2,5) of s4..." << endl;
  cout << "s4.substring(7) = " << s4.substring(2,5) << endl << endl;


  cout << "testing out .indexOf(MyString) - indexOf 'ten' in s4" << endl;
  cout << "s4.indexOf(MyString(\"ten\") = " << s4.indexOf(MyString("ten")) << endl << endl;


  cout << "testing out .lastIndexOf(MyString) - lastIndexOf 'e' in s4" << endl;
  cout << "s4.indexOf(MyString(\"e\") = " << s4.lastIndexOf(MyString("e")) << endl << endl;

}
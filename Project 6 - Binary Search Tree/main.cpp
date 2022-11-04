#include <iostream>
#include <fstream>

using namespace std;

//Enables/disables cout on search() function
bool sneakySearch = false;

struct node{
  string data;
  struct node* left;
  struct node* right;
  
  struct node* insert(struct node* node, string data){
    if(node == NULL){
      struct node* node = new(struct node);
      node->data = data;
      node->left = node->right = NULL;
      return node;
    }
    else{
      //Data is smaller, insert left
      if(data < node->data){
        node->left = insert(node->left, data);
      }
      //Data is bigger, insert right
      else{
        (node->right = insert(node->right, data));
      }
    }
    return node;
  }
  //Keeps track of recursive counter
  int counter = 0;
  int search(node *node, string target){
    if(node == NULL){
      if(!sneakySearch){
        cout << "\nInspected " << counter << " elements\n" << "'"  << target  << "' not in tree" << endl;
      }
      return false;
    }
    else{
      //If target is data, you found the target
      if (target == node->data){
        if(!sneakySearch){
          counter++;
          cout << "\nInspected " << counter << " elements\n" << "'"  << target  << "' located" << endl;
        }
        //Reset counter after you find the match or it will keep incrementing next search
        counter = 0;
        return true;
      }
      else{
        //Traversing the binary tree recursively, increment counter.
        counter++;
        //If target is less than the data, traverse left
        if(target < node->data){
          return(search(node->left, target));
        }
        //If target is greater than data, traverse right
        else{
          return(search(node->right,target));
        }
      }
    }
  }

  //Returns pointer to min value
  node* minVal(struct node* node){
    //New node to do the work
    struct node* current = node;
    //When we call this, we only want left. If NULL, we deleted a leaf, so no worries about making a forest
    while(current && current->left != NULL){
      current = current->left;
    }
    return current;
  }

  struct node* deleteNode(struct node* root, string key){
    //Base case
    if(root == NULL){
      return root;
    }
    //Recursive calls
    if(key < root->data){
      root->left = deleteNode(root->left, key);
    }
    else if(key > root->data){
      root->right = deleteNode(root->right, key);
    }
    else{
      //No left child, make right child successor
      if(root->left == NULL){
        struct node* temp = root->right;
        delete(root);
        return temp;
      }
      //No right child, make left child successor
      else if(root->right == NULL){
        struct node* temp = root->left;
        delete(root);
        return temp;
      }
      //If node has both children; get successor and then delete the node
      struct node* temp = minVal(root->right);
      //Copy the in-order successor's content to this node
      root->data = temp->data;
      //Delete the in-order successor
      root->right = deleteNode(root->right, key);
    }
    
    return root;
  }

  void display(node* temp){
    
    //Exit condition of recursive call
    if(temp == NULL){
      return;
    }
    //Go left until you hit NULL. Then pop back and try right, repeat until whole tree has been displayed.
    else{
      display(temp->left);
      cout << temp->data << ", ";
      display(temp->right);
    }

  }
};

//Thanks Project 3 for the reusable code :)
string toLower(string str) { 
  for(int i = 0; i < str.length(); i++){
    //Turn uppercase chars to lowercase
    if(str[i] >= 65 && str[i] <= 92){
      str[i] = str[i]+32;
    }
  }
	return str;
}

int main() {
	ifstream fin("textFactory.txt");
	string str;

  fin >> str;
  node noder = {
    .data = toLower(str)
  };

  sneakySearch = true;
	while (fin>>str) {
    //Check if duplicate word
    if(!noder.search(&noder,toLower(str))){
      noder.insert(&noder, toLower(str));
    }
	}
  sneakySearch = false;
	fin.close();

  int answer = -1;
  while(true){
    cout << endl;
    noder.display(&noder);
    cout << "\n\nWhat would you like to do? \n[1] Search \n[2] Delete \n[0] Quit\n\n";
    cin >> answer;
    while(answer < 0 || answer > 2 || cin.fail()){
      cin.clear();
			cin.ignore(256, '\n');
      cout << "\n\nWhat would you like to do? \n[1] Search \n[2] Delete \n[0] Quit\n\n";
      cin >> answer;
    }
    if(answer == 1){
      cout << "Search: ";
      cin >> str;
      noder.search(&noder,str);
    }
    else if (answer == 2){
      cout << "Delete: ";
      cin >> str;
      noder.deleteNode(&noder, str);
    }
    else{
      break;
    }
    answer = -1;
  }
  return 0;
}
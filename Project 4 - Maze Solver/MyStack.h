using namespace std;
template<class T>
struct Node {
  T data;
  struct Node* next;
  Node(T newData){
    data = newData;
    next = nullptr;
  }
};

template<class T>
class MyStack{

private:
  Node<T>* head;
  int length = 0;

public:
  MyStack(){
    head = nullptr;
    length = 0;
  }

  void push(T v){
    Node<T>* newNode = new Node<T>(v);
    newNode->next = head;
    head = newNode;
    length++;
  }

  int size(){
    return length;
  }

  bool empty(){
    //length == 0 returns true if empty, false if not.
    return (length == 0);
  }

  T top(){
    return head->data;
  }

  void pop(){
    if (!empty()){
      Node<T>* temp = head;
      head = temp->next == nullptr ? nullptr : temp->next;
      length--;
    }
  }
};
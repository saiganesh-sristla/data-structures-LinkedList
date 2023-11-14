#include <iostream>
using namespace std;

class Node {
  public:
  int data;
  Node* next;

  Node(int data){
    this -> data = data;
    this -> next = NULL;
  }
};

void insertNode(Node* &tail, int element, int data){
  if(tail == NULL){
    Node* temp = new Node(data);
    tail = temp;
    temp -> next = temp;
    return;
  }
  else{
    // Assuming that the element is present in the list

    Node* curr = tail;
    while(curr -> data != element){
      curr = curr -> next;
    }

    Node* temp = new Node(data);
    temp -> next = curr -> next;
    curr -> next = temp;

  }
}

void print(Node* tail){
  Node* temp = tail;
  cout << temp -> data << " ";
  temp = temp -> next;

  while(temp != tail){
    cout << temp -> data << " ";
    temp = temp -> next;
  }
  cout << endl;
}

int main() {
  Node* tail = NULL;

  insertNode(tail, 1, 3);
  print(tail);

  insertNode(tail, 3, 5);
  print(tail);

  insertNode(tail, 3, 4);
  print(tail);
  
  
  return 0;
}
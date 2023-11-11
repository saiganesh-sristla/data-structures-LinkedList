#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int data){
      this->data = data;
      this->next = NULL;
    }
};

void print(Node* head){
  Node* temp = head;

  while(temp != NULL){
    cout << temp -> data << " ";
    temp = temp -> next;
  }
  cout << endl;
}

void insertAtHead(Node* &head, int data){

  Node* temp = new Node(data);
  temp -> next = head;
  head = temp;

}

void insertAtTail(Node* &tail, int data){

  Node* temp = new Node(data);
  tail -> next = temp;
  tail = temp;

}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
  if(position == 1){
    insertAtHead(head, data);
    return;
  }

  Node* temp = head;
  int count = 1;
  while(count < position-1){
    temp = temp -> next;
    count++;
  }

  if(temp -> next == NULL){
    insertAtTail(tail, data);
    return;
  }

  Node* NodeToInsert = new Node(data);
  NodeToInsert -> next = temp -> next;
  temp -> next = NodeToInsert;
}

void deleteNode(Node* &head, Node* &tail, int position){
  if(position == 1){
    Node* temp = head;
    head = head -> next;
    temp -> next = NULL;
    delete temp;
  }
  else{
    Node* prev = NULL;
    Node* curr = head;
    int count = 1;

    while(count < position){
      prev = curr;
      curr = curr -> next;
      count++;
    }
    
    if(curr == tail){
      tail = prev;
      prev -> next = NULL;
      delete curr;
    }
    else{
      prev -> next = curr -> next;
      curr -> next = NULL;
      delete curr;
    }
  }
}

int main() {
  Node* Node1 = new Node(10);
  Node* head = Node1;
  Node* tail = Node1;

  print(head);
  insertAtHead(head, 20);
  print(head);

  insertAtTail(tail, 30);
  print(head);

  insertAtPosition(head, tail, 3, 22);
  print(head);

  insertAtPosition(head, tail, 1, 33);
  print(head);

  insertAtPosition(head, tail, 6, 44);
  print(head);

  deleteNode(head, tail, 2);
  print(head);
  cout << "head " << head -> data << endl;
  cout << "tail " << tail -> data << endl;

  return 0;
}
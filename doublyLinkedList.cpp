#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node* prev;

  Node(int data){
    this -> data = data;
    this -> next = NULL;
    this -> prev = NULL;
  }
};

void print(Node* &head){
  Node* temp = head;

  while(temp != NULL){
    cout << temp -> data << " ";
    temp = temp -> next;
  }
  cout << endl;
}

int getLength(Node * &head){
  Node* temp = head;
  int len = 0;

  while(temp != NULL){
    len++;
    temp = temp -> next;
  }
  return len;
}

void insertAtHead(Node* &head, int data){
  Node* temp = new Node(data);
  temp -> next = head;
  head -> prev = temp;
  head = temp;
}

void insertAtTail(Node* &tail, int data){
  Node* temp = new Node(data);
  tail -> next = temp;
  temp -> prev = tail;
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
  
  if(temp == tail){
    insertAtTail(tail, data);
    return;
  }

  Node* NodeToInsert = new Node(data);
  NodeToInsert -> next = temp -> next;
  temp -> next -> prev = NodeToInsert;
  temp -> next = NodeToInsert;
  NodeToInsert -> prev = temp;
}

int main() {
  Node* Node1 = new Node(2);
  Node* head = Node1;
  Node* tail = Node1;
  print(head);

  insertAtHead(head, 5);
  print(head);

  insertAtTail(tail, 3);
  print(head);

  insertAtPosition(head, tail, 2, 7);
  print(head);
  cout << "Length " << getLength(head) << endl;
  cout << "Head " << head -> data << endl;
  cout << "Tail " << tail -> data << endl;
  return 0;
}
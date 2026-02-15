#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

 Node * sort_accending(Node *head) {
  Node *current = head;
  Node *second = head->next;
  int isSwaped;

  while (isSwaped) {
    isSwaped = 0;

    if (current->data > second->data) {
      current->data = current->data + second->data;
      second->data = current->data - second->data;
      current->data = current->data - second->data;
      isSwaped = 1;
    }

    if (second->next == nullptr) {
      current = head;
      second = head->next;
    }

    current = second;
    second = second->next;
  }

  Node *curren= head;
  while (curren != nullptr) {
    cout << curren->data << " -> ";
    curren = curren->next;
  }
  cout << "NULL\n\n\n";
}

int main() {
  // Declare and initialize head node
  Node *head = new Node();
  head->data = 21;
  head->next = nullptr;

  // Create 5 more nodes
  Node *second = new Node();
  second->data = 12;
  second->next = nullptr;

  Node *third = new Node();
  third->data = 3;
  third->next = nullptr;

  Node *fourth = new Node();
  fourth->data = 33;
  fourth->next = nullptr;

  Node *fifth = new Node();
  fifth->data = 15;
  fifth->next = nullptr;

  Node *sixth = new Node();
  sixth->data = 6;
  sixth->next = nullptr;

  // Link them together
  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;

  head = sort_accending(head);

  // Print list
  Node *current = head;
  while (current != nullptr) {
    cout << current->data << " -> ";
    current = current->next;
  }
  cout << "NULL\n\n\n";

  // Cleanup memory
  current = head;
  while (current != nullptr) {
    Node *nextNode = current->next;
    delete current;
    current = nextNode;
  }

  return 0;
}
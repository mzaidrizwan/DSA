#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

// function to reverse the list
Node *reverse(Node *head) {
  Node *second = head->next,*third;
  head->next = nullptr;
  int b = 0;

  while (b < 1) {

    if (second->next != nullptr)
      third = second->next;
    else
      ++b;

    second->next = head;
    head = second;
    second = third;
  }
  return head;
}

int main() {
  // Declare and initialize head node
  Node *head = new Node();
  head->data = 1;
  head->next = nullptr;

  // Create 5 more nodes
  Node *second = new Node();
  second->data = 2;
  second->next = nullptr;

  Node *third = new Node();
  third->data = 3;
  third->next = nullptr;

  Node *fourth = new Node();
  fourth->data = 4;
  fourth->next = nullptr;

  Node *fifth = new Node();
  fifth->data = 5;
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

  // Print list
  Node *current = head;
  while (current != nullptr) {
    cout << current->data << " -> ";
    current = current->next;
  }
  cout << "NULL\n\n\n";

  head = reverse(head);

  // Print Reversed list
  current = head;
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
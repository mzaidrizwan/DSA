#include <cstddef>
#include <iostream>
using namespace std;

// CREATING CUSTOM DATA TYPE
struct Node {
  int data;
  Node *next;
};

// PRINT LINKEDLIST
void printList(Node *head) {
  Node *currentNode = head;

  while (currentNode != NULL) {
    cout << currentNode->data << " - ";
    currentNode = currentNode->next;
  }
}

// CUSTOM NODES CREATOR
Node *createNode(int data) {
  Node *node = new Node();
  node->data = data;
  node->next = nullptr;
  return node;
}

int main() {

  // DECLARE HEAD NODE
  Node *head = new Node();

  // INITIALIZE HEADH
  head->data = NULL;
  head->next = nullptr;
  while (1) {

    cout << "add new data\n";
    int userInputData;
    cin >> userInputData;

    Node *newNode = createNode(userInputData);
    if (head->data == NULL) {
      head->data = newNode->data;
      continue;
    }

    cout << "position of this new data?\n1. Beginning\n2. End\n3. I want to tell position";
    int userInputPosition;
    cin >> userInputPosition;

    if (userInputPosition == 1) {
      int temp_stored_data = newNode->data;
      Node *temp_stored_next = newNode;

      newNode->data = head->data;
      newNode->next = head->next;

      head->data = temp_stored_data;
      head->next = temp_stored_next;
    }

    printList(head);
    break;
  }
  return 0;
}
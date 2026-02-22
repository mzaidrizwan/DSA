#include <iostream>
using namespace std;

// create custom data type
struct Node {
  Node *prev;
  int data;
  Node *next;

  // constructor
  Node(int value, Node *p = nullptr, Node *n = nullptr) {
    data = value;
    prev = p;
    next = n;
  }
};

int main() {
  Node *head = nullptr; // start with empty list
  int userInp;

  while (true) {
    cout << "enter -1 to close program.\n1. Insert New Data at beginning.\n2. "
            "Insert New Data at End.\n3. Count total number of nodes\n 4. Search a value\n";
    cin >> userInp;
    cout << endl;

    if (userInp == -1) {
      break;
    }

    if (userInp == 1) {
      int userInpData;
      cout << "\nEnter data value:\n";
      cin >> userInpData;

      if (head != nullptr) {
        // insert at beginning
        Node *newNode = new Node(userInpData, nullptr, head);
        head->prev = newNode;
        head = newNode;
      } else {
        // first node
        head = new Node(userInpData);
      }
    } else if (userInp == 2) {

      int userInpData;
      cout << "\nEnter data value:\n";
      cin >> userInpData;

      if (head != nullptr) {
        Node *tempNode = head;
        while (tempNode->next != nullptr)
          tempNode = tempNode->next;
        Node *newNode = new Node(userInpData, tempNode, nullptr);
        tempNode->next = newNode;
      } else {
        head = new Node(userInpData);
      }
    } else if (userInp == 3) {
      if (head != nullptr) {
        int length = 0;
        Node *tempNode = head;
        while (tempNode != nullptr) {
          ++length;
          tempNode = tempNode->next;
        }
        cout << "\nlength of list is " << length << endl << endl;
      } else {
        cout << "\n list is empty\n\n\n";
      }
    } else if (userInp == 4) {
      int userInpData, position = 0;
      bool found = false;
      cout << "\nEnter a value to search: ";
      cin >> userInpData;

      if (head != nullptr) {
        Node *tempNode = head;

        while (tempNode != nullptr) {
          position++;

          if (tempNode->data == userInpData) {
            found = true;
            break;
          }

          tempNode = tempNode->next;
        }
        if (found) {
          cout << "\n\n present at position " << position << endl;
        } else {
          cout << "\n\nnot found\n";
        }

      } else {
        cout << "\nlist is empty\n";
      }
    }
  }

  // print list
  cout << "\nFinal list:\n";
  Node *current = head;
  while (current != nullptr) {
    cout << current->data << " -> ";
    current = current->next;
  }
  cout << "NULL\n";

  // cleanup memory
  current = head;
  while (current != nullptr) {
    Node *nextNode = current->next;
    delete current;
    current = nextNode;
  }

  return 0;
}

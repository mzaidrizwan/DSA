#include <algorithm>
#include <cstddef>
#include <iostream>
using namespace std;

// create custom node
struct Node {
  Node *left;
  int data;
  Node *right;
  Node *parent;

  // constructor
  Node(int value, Node *parenT = nullptr, Node *lefT = nullptr,
       Node *righT = nullptr) {
    data = value;
    left = lefT;
    right = righT;
    parent = parenT;
  }
};
Node *head = new Node(NULL);

void add(int data) {
  if (head->data != NULL) {
    Node *currentPosition = head, *newNode = nullptr;
    while (1) {

      if (data < currentPosition->data) { // if data is less than current node

        if (currentPosition->left != nullptr) {
          currentPosition = currentPosition->left;
        } else {
          newNode = new Node(data, currentPosition);
          currentPosition->left = newNode;
          break;
        }

      } else if (data > currentPosition
                            ->data) { // if data is greater than current node

        if (currentPosition->right != nullptr) {
          currentPosition = currentPosition->right;
        } else {
          newNode = new Node(data, currentPosition);
          currentPosition->right = newNode;
          break;
        }

      } else if (data ==
                 currentPosition->data) { // if data is equal to current node
        if (currentPosition->left != nullptr) {
          currentPosition = currentPosition->left;
        } else {
          newNode = new Node(data, currentPosition);
          currentPosition->left = newNode;
          break;
        }
      }
    }

    cout << data << " is now node of " << currentPosition->data << endl;

  } else {
    head->data = data;
    cout << data << " is now Head node. " << endl;
  }
}

void searchInBST(int data) {
  Node *currentPosition = head;

  while (1) {
    if (data < currentPosition->data) {
      if (currentPosition->left != nullptr)
        currentPosition = currentPosition->left;
      else {
        cout << " Not Found-1";
        break;
      }
    } else if (data > currentPosition->data) {
      if (currentPosition->right != nullptr)
        currentPosition = currentPosition->right;
      else {
        cout << " Not Found-2";
        break;
      }
    } else if (data == currentPosition->data) {
      cout << data << " is present as Child Node of " << currentPosition->parent->data;
      break;
    }
  }
}

int main() {
  while (1) {
    cout << "\n1. Add data\n2. Search Value\n";
    int userInp;
    cin >> userInp;

    if (userInp == 1) {
      cout << "Enter data value: ";
      int data;
      cin >> data;
      add(data);
    } else if (userInp == 2) {
      cout << "Enter value to search: ";
      int data;
      cin >> data;
      searchInBST(data);
    }
  }
}
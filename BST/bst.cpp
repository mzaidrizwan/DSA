#include <algorithm>
#include <cstddef>
#include <exception>
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

Node *searchInBST(int data) {
  Node *currentPosition = head;

  while (1) {
    if (data < currentPosition->data) {
      if (currentPosition->left != nullptr)
        currentPosition = currentPosition->left;
      else {
        cout << " Not Found";
        break;
      }
    } else if (data > currentPosition->data) {
      if (currentPosition->right != nullptr)
        currentPosition = currentPosition->right;
      else {
        cout << " Not Found ";
        break;
      }
    } else if (data == currentPosition->data) {
      return currentPosition;
      break;
    }
  }
}

void deletE(int data) {
  if (Node *currentPosition = searchInBST(data))
    while (1) {
      bool NoLeftNode = currentPosition->left == nullptr,
           NoRightNode = currentPosition->right == nullptr;

      if (NoLeftNode && NoRightNode) { // if it's leaf node

        Node *parent_left = currentPosition->parent->left;
        Node *parent_right = currentPosition->parent->right;
        if (parent_left->data == currentPosition->data) {
          parent_left = nullptr;
          cout << "\ndeleted as " << currentPosition->parent->data
               << "'s left node\n";
        } else {
          parent_right = nullptr;
          cout << "\ndeleted as " << currentPosition->parent->data
               << "'s right node\n";
        }
        break;
      } else if (NoLeftNode || NoRightNode) { // if have just one child
        if (NoLeftNode) {                     // linking direct with its parent
          currentPosition->parent->right = currentPosition->right;
          currentPosition->right->parent = currentPosition->parent;
          cout << "\ndeleted as " << currentPosition->parent->data
               << "'s right node\n";
        } else { // linking direct with its parent
          currentPosition->parent->left = currentPosition->left;
          currentPosition->left->parent = currentPosition->parent;
          cout << "\ndeleted as " << currentPosition->parent->data
               << "'s left node\n";
        }

        delete currentPosition;
      } else if (!NoLeftNode && !NoRightNode) {
        Node *parent = currentPosition->parent;
        currentPosition = currentPosition->left;
        do {
currentPosition=
        } while ()
      }
    }
}

int main() {
  while (1) {
    cout << "\n1. Add data\n2. Search Value\n3. Delete a Node.\n";
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
      cout << data << " is present as Child Node of "
           << searchInBST(data)->parent->data;
    } else if (userInp == 3) {
      cout << "Enter value to delete: ";
      int data;
      cin >> data;
      deletE(data);
    }
  }
}
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
  Node *head = nullptr, *tail = nullptr; // start with empty list
  int userInp;

  cout << "=============================================\n";
  cout << "        DOUBLY LINKED LIST MANAGER\n";
  cout << "=============================================\n";

  while (true) {

    cout << "\n---------------------------------------------\n";
    cout << "Choose an Operation:\n";
    cout << "---------------------------------------------\n";
    cout << "  1  -> Enqueue\n";
    cout << "  2  -> Dequeue\n";
    cout << "  3  -> Forward Traverse\n";
    cout << "  4  -> Backward Traverse\n";
    cout << " -1  -> Exit Program\n";
    cout << "---------------------------------------------\n";
    cout << "Enter your choice: ";
    cin >> userInp;
    cout << endl;

    if (userInp == -1) {
      cout << "\nProgram terminated successfully.\n";
      cout << "Cleaning up memory...\n";
      break;
    }

    
    if (userInp == 1) {
      cout << "[Enqueue]\n";
      int userInpData;
      cout << "Enter data value: ";
      cin >> userInpData;

      if (head != nullptr) {
        Node *tempNode = head;
        while (tempNode->next != nullptr)
          tempNode = tempNode->next;
        Node *newNode = new Node(userInpData, tempNode, nullptr);
        tempNode->next = newNode;
        tail = newNode;
      } else {
        head = new Node(userInpData);
      }

      cout << "Data inserted successfully in Queue.\n";
    }else if (userInp == 2) {
      cout << "[Dequeue]\n";
      if (head != nullptr) {
        Node *tempNode = head;
        head = head->next;
        if (head != nullptr)
          head->prev = nullptr;
        delete tempNode;
        cout << "data deleted successfully.\n";
      } else {
        cout << "Queue is empty.\n";
      }
    }   else if (userInp == 3) {
      cout << "[Forward Traversal]\n";
      if (head != nullptr) {
        Node *current = head;
        cout << "HEAD <-> ";
        while (current != nullptr) {
          cout << current->data << " <-> ";
          current = current->next;
        }
        cout << "NULL\n";
      } else {
        cout << "List is empty.\n";
      }
    }else if (userInp == 4) {
      cout << "[Backward Traversal]\n";
      if (head != nullptr) {
        Node *tempNode = tail;
        cout << "NULL <-> ";
        while (tempNode != nullptr) {
          cout << tempNode->data << " <-> ";
          tempNode = tempNode->prev;
        }
        cout << "HEAD\n";
      } else {
        cout << "List is empty.\n";
      }
    }
  }

    // cleanup memory
  Node *tempNode = head;
  while (tempNode != nullptr) {
    Node *tailored = tempNode->next;
    delete tempNode;
    tempNode = tailored;
  }
}
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

  while (true) {
    cout << "enter -1 to close program.\n1. Insert New Data at beginning.\n2. "
            "Insert New Data at End.\n3. Count total number of nodes\n 4. "
            "Search a value\n5. insert after a specific data value.\n6. print "
            "in forward traversal.\n7. Delete a node at beginning.\n8. Delete "
            "a node at last.\n9. delete a node after a specific data "
            "value.\n10. Print in Backward Traversel\n11. reverse the "
            "list\n12. Merge a new List\n";
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
        tail = head;
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
        tail = newNode;
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
    } else if (userInp == 5) {
      int userInpData, userInpPosition;
      bool found = false;
      cout << "\nEnter new data value: ";
      cin >> userInpData;

      cout << "\nEnter data value after which the new data to insert: ";
      cin >> userInpPosition;

      if (head != nullptr) {
        Node *tempNode = head;
        while (tempNode != nullptr) {

          if (tempNode->data == userInpPosition) {
            break;
            found = true;
          }

          tempNode = tempNode->next;
        }

        if (found && tempNode->next != nullptr) {
          Node *newNode = new Node(userInpData, tempNode, tempNode->next);
          tempNode->next = newNode;
        } else if (tempNode->next ==
                   nullptr) { // to handle inserting at the last position
                              // without using inserAtEnd() function.
          Node *newNode = new Node(userInpData, tempNode, nullptr);
          tempNode->next = newNode;
          tail = newNode;
        } else if (!found) {
          cout << "\nentered postion not found\n";
        }
      }
    } else if (userInp == 7) {
      if (head != nullptr) {
        Node *tempNode = head;
        head = head->next;
        head->prev = nullptr;
        delete tempNode;
      } else {
        cout << "\nlist is empty\n";
      }
    } else if (userInp == 6) {
      // print in forward traversal
      cout << endl;
      Node *current = head;
      while (current != nullptr) {
        cout << current->data << " -> ";
        //  cout << endl<<current->prev<<" | "<<current->data<<" |
        //  "<<current->next;
        current = current->next;
      }
      cout << "NULL\n";
    } else if (userInp == 8) {
      if (head != nullptr) {
        Node *nodeToDelete = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete nodeToDelete;
      }
    } else if (userInp == 9) {
      int userInpPosition;
      bool found = false;

      cout << "\nEnter data value after which the node to delete: ";
      cin >> userInpPosition;

      Node *tempNode = head;

      while (tempNode != nullptr) {
        if (tempNode->data == userInpPosition) {
          found = true;
          break;
        }
        tempNode = tempNode->next;
      }

      if (found && tempNode->next != tail) {
        Node *nodeToDelete = tempNode->next;
        tempNode->next = nodeToDelete->next;
        Node *tempPrevious = tempNode;
        tempNode = tempNode->next;
        tempNode->prev = tempPrevious;
        delete nodeToDelete;
      } else if (found && tempNode->next == tail) {
        tail = tail->prev;
        tempNode = tempNode->next;
        tail->next = nullptr;
        delete tempNode;
      } else if (!found) {
        cout << "\ngiven position not found\n";
      }
    } else if (userInp == 10) {
      if (head != nullptr) {
        Node *tempNode = tail;
        while (tempNode != nullptr) {
          cout << " <- " << tempNode->data;
          tempNode = tempNode->prev;
        }
        cout << "NULL <- ";
      } else {
        cout << "\nlist is empty\n";
      }
    } else if (userInp == 11) {
      if (head != nullptr) {
        Node *tempNode = head;
        Node *prev = nullptr, *tempPrev = nullptr, *next = nullptr;
        while (tempNode != nullptr) {
          prev = tempNode->prev;
          next = tempNode->next;

          tempPrev = prev;
          tempNode->prev = next;
          tempNode->next = tempPrev;

          tempNode = next;
        }

        tail = head;
        head = prev->prev;
      }
    } else if (userInp == 12) {
      if (head != nullptr) {
        string userInpList;
        int data=0;
        cout << "\nenter a List to merge with( example format -2-3-4- ):\n";
        cin >> userInpList;

        for (int i = 0; i < userInpList.length(); i++) {

          
          if (userInpList[i] >= '0' && userInpList[i] <= '9') {
            data = data * 10 + (userInpList[i] - 48); // converting string into integer.
          }else if (i!=0){
          Node * newNode = new Node(data,tail);
          tail->next=newNode;
          tail=newNode;
          data=0;
          }
        }
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

  return 0;
}
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
  cout << "Interactive Console Application\n";

  while (true) {

    cout << "\n---------------------------------------------\n";
    cout << "Choose an Operation:\n";
    cout << "---------------------------------------------\n";
    cout << "  1  -> Insert at Beginning\n";
    cout << "  2  -> Insert at End\n";
    cout << "  3  -> Count Total Nodes\n";
    cout << "  4  -> Search a Value\n";
    cout << "  5  -> Insert After Specific Value\n";
    cout << "  6  -> Print Forward Traversal\n";
    cout << "  7  -> Delete at Beginning\n";
    cout << "  8  -> Delete at End\n";
    cout << "  9  -> Delete After Specific Value\n";
    cout << " 10  -> Print Backward Traversal\n";
    cout << " 11  -> Reverse the List\n";
    cout << " 12  -> Merge Another List\n";
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
      cout << "[Insert at Beginning]\n";
      int userInpData;
      cout << "Enter data value: ";
      cin >> userInpData;

      if (head != nullptr) {
        Node *newNode = new Node(userInpData, nullptr, head);
        head->prev = newNode;
        head = newNode;
      } else {
        head = new Node(userInpData);
        tail = head;
      }

      cout << "Node inserted successfully.\n";
    }

    else if (userInp == 2) {
      cout << "[Insert at End]\n";
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

      cout << "Node inserted successfully.\n";
    }

    else if (userInp == 3) {
      cout << "[Count Total Nodes]\n";
      if (head != nullptr) {
        int length = 0;
        Node *tempNode = head;
        while (tempNode != nullptr) {
          ++length;
          tempNode = tempNode->next;
        }
        cout << "Total number of nodes: " << length << endl;
      } else {
        cout << "List is empty.\n";
      }
    }

    else if (userInp == 4) {
      cout << "[Search Operation]\n";
      int userInpData, position = 0;
      bool found = false;
      cout << "Enter a value to search: ";
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

        if (found)
          cout << "Value found at position " << position << endl;
        else
          cout << "Value not found in list.\n";
      } else {
        cout << "List is empty.\n";
      }
    }

    else if (userInp == 5) {
      cout << "[Insert After Specific Value]\n";
      int userInpData, userInpPosition;
      bool found = false;
      cout << "Enter new data value: ";
      cin >> userInpData;

      cout << "Enter data value after which to insert: ";
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
        } else if (tempNode->next == nullptr) {
          Node *newNode = new Node(userInpData, tempNode, nullptr);
          tempNode->next = newNode;
          tail = newNode;
        } else if (!found) {
          cout << "Given position not found.\n";
        }

        cout << "Operation completed.\n";
      }
    }

    else if (userInp == 6) {
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
    }

    else if (userInp == 7) {
      cout << "[Delete at Beginning]\n";
      if (head != nullptr) {
        Node *tempNode = head;
        head = head->next;
        if (head != nullptr)
          head->prev = nullptr;
        delete tempNode;
        cout << "Node deleted successfully.\n";
      } else {
        cout << "List is empty.\n";
      }
    }

    else if (userInp == 8) {
      cout << "[Delete at End]\n";
      if (head != nullptr) {
        Node *nodeToDelete = tail;
        tail = tail->prev;
        if (tail != nullptr)
          tail->next = nullptr;
        delete nodeToDelete;
        cout << "Node deleted successfully.\n";
      } else {
        cout << "List is empty.\n";
      }
    }

    else if (userInp == 9) {
      cout << "[Delete After Specific Value]\n";
      int userInpPosition;
      bool found = false;

      cout << "Enter data value after which to delete: ";
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
        cout << "Node deleted successfully.\n";
      } else if (found && tempNode->next == tail) {
        tail = tail->prev;
        tempNode = tempNode->next;
        tail->next = nullptr;
        delete tempNode;
        cout << "Node deleted successfully.\n";
      } else if (!found) {
        cout << "Given position not found.\n";
      }
    }

    else if (userInp == 10) {
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

    else if (userInp == 11) {
      cout << "[Reverse List]\n";
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

        cout << "List reversed successfully.\n";
      } else {
        cout << "List is empty.\n";
      }
    }

    else if (userInp == 12) {
      cout << "[Merge Another List]\n";
      if (head != nullptr) {
        string userInpList;
        int data = 0;
        cout << "Enter list to merge (example format -2-3-4-): ";
        cin >> userInpList;

        for (int i = 0; i < userInpList.length(); i++) {
          if (userInpList[i] >= '0' && userInpList[i] <= '9') {
            data = data * 10 + (userInpList[i] - 48);
          } else if (i != 0) {
            Node *newNode = new Node(data, tail);
            tail->next = newNode;
            tail = newNode;
            data = 0;
          }
        }

        cout << "List merged successfully.\n";
      } else {
        cout << "List is empty. Cannot merge.\n";
      }
    }

    else {
      cout << "Invalid choice. Please try again.\n";
    }

    cout << "---------------------------------------------\n";
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
#include <cstddef>
#include <iostream>//reverse likned list iteratively,sort in acsending order.
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

// INSERT NEW NODE AT BEGINNING
void inserAtBeginning(Node *head, Node *newNode) {
  int temp_stored_data = newNode->data;
  Node *temp_stored_next = newNode;

  newNode->data = head->data;
  newNode->next = head->next;

  head->data = temp_stored_data;
  head->next = temp_stored_next;
}

// COUNT TOTAL NUMBER OF NODES
int countTotalNodes(Node *currentNode) {
  int i = 0;
  while (currentNode != NULL) {
    currentNode = currentNode->next;
    ++i;
  }
  return i;
}

int searchNode(Node *currentNode, int toFind) {
  int i = 1;
  bool found = false;

  while (currentNode != NULL) {
    if (currentNode->data == toFind) {
      found = true;
      break;
    }
    currentNode = currentNode->next;
    ++i;
  }

  if (found == true) {
    return i;
  } else {
    return 0;
  }
}

void deleteLastNode(Node *currentNode) {
  Node *prev;

  while (currentNode->next != nullptr) {
    prev = currentNode;
    currentNode = currentNode->next;
  }
  prev->next = currentNode->next;
  delete currentNode;
}

int main() {

  // DECLARE HEAD NODE
   Node *head = new Node();

  // INITIALIZE HEAD
  head->data = NULL;
  head->next = nullptr;

  while (1) {
    cout << "\n\n\n1. insert Data.\n2. Count total of nodes.\n3. Search "
            "a "
            "value.\n4. Delete Last Node";
    int userInputOption;
    cin >> userInputOption;

    if (userInputOption == 1) {
      while (1) {

        cout << "add new data, type -1 to stop insertion\n";
        int userInputData;
        cin >> userInputData;

        if (userInputData == -1) {
          break;
        }

        Node *newNode = createNode(userInputData);
        if (head->data == NULL) {
          head->data = newNode->data;
          continue;
        }

        // cout << "Select an option?\n1. Beginning\n2. End\n3. I want to tell "
        //         "position\n\n";
        cout << "Select an option?\n1. Beginning\n";
        int userInputOption;
        cin >> userInputOption;

        if (userInputOption == 1) {
          inserAtBeginning(head, newNode);
        }
        // printList(head);
        // break;
      }
    } else if (userInputOption == 2) {
      cout << "\nTotal number of nodes: " << countTotalNodes(head) << endl;
    } else if (userInputOption == 3) {
      cout << "\nEnter value to search: \n";
      int toFind;
      cin >> toFind;
      int searchResult = searchNode(head, toFind);
      if (searchResult == 0) {
        cout << "\nNot found\n";
      } else {
        cout << "\nPresent at Node#" << searchResult << endl;
      }
    } else if (userInputOption == 4) {
      deleteLastNode(head);
      if (head!=NULL) {
        printList(head);
      }
    } else if (userInputOption == -1) {
      break;
    }
  }
  return 0;
}
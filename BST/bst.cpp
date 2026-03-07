#include <cstddef>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Node {
    Node *left;
    int data;
    Node *right;
    Node *parent;

    Node(int value, Node *parenT = nullptr, Node *lefT = nullptr, Node *righT = nullptr) {
        data = value;
        left = lefT;
        right = righT;
        parent = parenT;
    }
};

// Initialize head as nullptr for a cleaner start
Node *head = nullptr;

// --- YOUR LOGIC START ---

void add(int data) {
    if (head != nullptr) {
        Node *currentPosition = head, *newNode = nullptr;
        while (1) {
            if (data < currentPosition->data) {
                if (currentPosition->left != nullptr) {
                    currentPosition = currentPosition->left;
                } else {
                    newNode = new Node(data, currentPosition);
                    currentPosition->left = newNode;
                    break;
                }
            } else { // Handles > and == as per your original logic
                if (currentPosition->right != nullptr) {
                    currentPosition = currentPosition->right;
                } else {
                    newNode = new Node(data, currentPosition);
                    currentPosition->right = newNode;
                    break;
                }
            }
        }
        cout << "\n[SUCCESS] " << data << " added as child of " << currentPosition->data << endl;
    } else {
        head = new Node(data);
        cout << "\n[SUCCESS] " << data << " is now the Root node." << endl;
    }
}

Node *searchInBST(int data) {
    if (!head) return nullptr;
    Node *currentPosition = head;
    while (currentPosition != nullptr) {
        if (data < currentPosition->data) {
            currentPosition = currentPosition->left;
        } else if (data > currentPosition->data) {
            currentPosition = currentPosition->right;
        } else {
            return currentPosition;
        }
    }
    return nullptr;
}

void deletE(int data) {
    Node* node = searchInBST(data);
    if (!node) {
        cout << "\n[ERROR] Value " << data << " not found in tree." << endl;
        return;
    }

    bool noLeft  = node->left  == nullptr;
    bool noRight = node->right == nullptr;

    if (noLeft && noRight) {
        if (node->parent == nullptr) head = nullptr;
        else if (node->parent->left == node) node->parent->left = nullptr;
        else node->parent->right = nullptr;
        delete node;
    }
    else if (noLeft || noRight) {
        Node* child = noLeft ? node->right : node->left;
        child->parent = node->parent;
        if (node->parent == nullptr) head = child;
        else if (node->parent->left == node) node->parent->left = child;
        else node->parent->right = child;
        delete node;
    }
    else {
        Node* predecessor = node->left;
        while (predecessor->right != nullptr)
            predecessor = predecessor->right;

        node->data = predecessor->data;
        Node* predChild = predecessor->left;
        
        // This handles the two-child logic you wrote
        if (predecessor->parent->right == predecessor)
            predecessor->parent->right = predChild;
        else
            predecessor->parent->left = predChild;

        if (predChild != nullptr)
            predChild->parent = predecessor->parent;

        delete predecessor;
    }
    cout << "\n[SUCCESS] Value " << data << " has been deleted." << endl;
}

void printInOrder() {
    if (!head) {
        cout << "Tree is empty.";
        return;
    }
    stack<Node*> stk;
    Node* current = head;
    while (current != nullptr || !stk.empty()) {
        while (current != nullptr) {
            stk.push(current);
            current = current->left;
        }
        current = stk.top();
        stk.pop();
        cout << current->data << "  ";
        current = current->right;
    }
}

// --- UI HELPERS ---

void showHeader() {
    cout << "\n========================================" << endl;
    cout << "      BINARY SEARCH TREE MANAGER        " << endl;
    cout << "========================================" << endl;
}

void showMenu() {
    cout << "\n[1] Add New Data" << endl;
    cout << "\n[2] Search for a Value" << endl;
    cout << "\n[3] Delete a Node" << endl;
    cout << "\n[4] Display In-Order Traversal" << endl;
    cout << "\n[0] Exit Program" << endl;
    cout << "\nSelection > ";
}

// --- MAIN LOOP ---

int main() {
    int choice;
    int val;

    while (true) {
        showHeader();
        showMenu();
        
        if (!(cin >> choice)) {
            cout << "\n[!] Invalid input. Please enter a number." << endl;
            cin.clear();
            while (cin.get() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter integer to add: ";
                cin >> val;
                add(val);
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> val;
                {
                    Node* found = searchInBST(val);
                    if (found) {
                        cout << "\n[FOUND] " << val << " exists in the tree.";
                        if (found->parent) 
                            cout << " (Parent: " << found->parent->data << ")";
                        else 
                            cout << " (This is the Root)";
                        cout << endl;
                    } else {
                        cout << "\n[NOT FOUND] " << val << " is not in the tree." << endl;
                    }
                }
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> val;
                deletE(val);
                break;
            case 4:
                cout << "\nIn-Order Traversal: [ ";
                printInOrder();
                cout << "]\n";
                break;
            case 0:
                cout << "\nExiting... Goodbye!\n";
                return 0;
            default:
                cout << "\n[!] Invalid selection. Try again." << endl;
        }
        
        cout << "\nPress Enter to continue...";
        cin.ignore(1000, '\n');
        cin.get();
    }
}
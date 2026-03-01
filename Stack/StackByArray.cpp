#include <iostream>
using namespace std;
int stack[3];
int rear = -1, numberOfElement = 0;
int length = sizeof(stack) / sizeof(int);

void push(int data) {

  if (length != numberOfElement) {

    stack[++rear] = data;
    ++numberOfElement;

  } else
    cout << " overflow ";
}

void pop() {
  if (rear != -1) {
    stack[rear--] = -1;
    --numberOfElement;
  } else
    cout << " overflow ";
}

void print() {
  for (int i = 0; i <= rear; i++) {
    cout << stack[i] << "~";
  }
}

int main() {
  while (1) {

    cout << "\n1. push\n2. pop\n3. Print stack\n4. Check Either the "
            "Queue is Empty or Not.\n";
    int userInp;
    cin >> userInp;

    if (userInp == 1) {
      cout << "\nEnter data to insert: ";
      int userInpData;
      cin >> userInpData;

      push(userInpData);
    } else if (userInp == 2)
      pop();
    else if (userInp == 3)
      print();
    else if (userInp = -1)
      break;
    ;
  }
}
#include <iostream>
#include <iterator>
using namespace std;

int queue[3];
int rear = -1, front = -1;
int length = sizeof(queue) / sizeof(int);

void enqueue(int data) {

  if (rear != length - 1) {

      if (rear != -1) {
        rear = (rear + 1) % length;
      queue[rear] = data;
    } else {
      queue[++rear] = data;
      front = rear;
    }

  } else
    cout << " not enough space ";
}

int main() {

  while (1) {

    cout << "\n1. Engueue\n2. dequeue\n3. Print Queue\n4. Return the Front"
            "element.\n5. Check Either the Queue is Empty or Not.\n";
    int userInp;
    cin >> userInp;

    if (userInp == 1) {

      cout << "\nEnter data to insert: ";
      int userInpData;
      cin >> userInpData;

      enqueue(userInpData);
    } else if (userInp == 2) {

       } else if (userInp == 3) {

        cout<<"\n front "<<front<< " | "<<" rear "<<rear<<endl;

      for (int i = front; i <= rear || i >= front; i = (i + 1) % length) {
        cout << queue[i] << "~";
      }
    }
  }
}
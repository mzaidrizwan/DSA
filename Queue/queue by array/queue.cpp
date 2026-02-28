#include <iostream>
using namespace std;

int queue[10];
int rear = -1;
int length = sizeof(queue) / sizeof(int);

int peak() { return queue[0]; }

int isEmptyORnot() {
  if (rear != -1) {
    return rear + 1;
  } else {
    return 0;
  }
}

int main() {

  while (1) {

    cout << "\n1. Engueue\n2. dequeue\n3. Print Queue\n4. Return the Front"
            "element.\n5. Check Either the Queue is Empty or Not.\n";
    int userInp;
    cin >> userInp;

    if (userInp == 1) {

      if (rear == length - 1) {
        cout << " not enough space ";
        continue;
      }

      cout << "\nEnter data to insert: ";
      int userInpData;
      cin >> userInpData;

      if (rear != -1) {
        queue[++rear] = userInpData;
      } else {
        queue[++rear] = userInpData;
      }
    } else if (userInp == 2) {

      if (rear != -1) {

        for (int i = 0; i < rear; i++) {
          queue[i] = queue[i + 1];
        }
        --rear;

      } else {
        cout << " underflow ";
        continue;
      }
    } else if (userInp == 3) {

      for (int i = 0; i <= rear; i++) {
        cout << queue[i] << "~";
      }
    } else if (userInp == 4) {
      cout << " front element : " << peak();
    } else if (userInp == 5) {
      int isEmpty = isEmptyORnot();

      if (isEmpty)
        cout << "contains " << isEmpty << " elements";
      else
        cout << " Empty ";

    } else
      break;
  }
}

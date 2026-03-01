#include <iostream>
#include <type_traits>
using namespace std;

int queue[3];
int rear = -1, front = -1,numberOfElement=0;
int length = sizeof(queue) / sizeof(int);

void enqueue(int data) {

  if (length!=numberOfElement) {

      if (rear != -1) {
        rear = (rear + 1) % length;
      queue[rear] = data;
    } else {
      queue[++rear] = data;
      front = rear;
    }
++numberOfElement;

  } else
    cout << " overflow ";
}

void dequeue(){
  if (front!=-1) {
    queue[front]=-1;
    front=(front+1)%length;
    --numberOfElement;
  }else {
  cout << " underflow ";
  }
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
dequeue();
       } else if (userInp == 3) {

        cout<<"\n front "<<front<< " | "<<" rear "<<rear<<endl;

      for (int i = front,j=numberOfElement; (i <= rear || i >= front)&&j; i = (i + 1) % length) {
        cout << queue[i] << "~";--j;
      }
    }
  }
}
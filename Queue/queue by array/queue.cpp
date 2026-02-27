#include <iostream>
using namespace std;
int main() {
cout << " enter length of queue list: ";
    int length;
    cin >> length;
    int queue[length];
    int rear = -1;
  while (1) {
    

    cout << "\n1. Engueue\n2. dequeue\n3. Print Queue\n";
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

        for (int i = 0; i < rear ; i++) {
          queue[i] = queue[i + 1];
        }--rear;

      } else {
        cout << " underflow ";
        continue;
      }
    } else if(userInp==3){

      for (int i = 0; i <= rear ; i++) {
      cout<<queue[i]<<"~";
      }


     

    }else break;
  }
}


#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] <= arr[high]) {
      swap(arr[++i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {

  vector<int> arr;
  int userInp;
  while (1) {
    cout << "Enter integers in array (-1 to stop inputting): ";
    cin >> userInp;
    if (userInp == -1)
      break;
    arr.push_back(userInp);
  }
  quickSort(arr, 0, arr.size() - 1);
  for (int n : arr)
    cout << n << " ";
}
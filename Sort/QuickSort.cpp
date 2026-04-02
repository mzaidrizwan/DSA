#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int partitioner(vector<int> &arr, int i, int pvt) {
  size_t j = 0;
  for (; j < arr.size(); j++) {
    if (arr[j] <= arr[pvt] || j == pvt) {
      swap(arr[++i], arr[j]);
    }
  }
  return j;
}

void QuickSort(vector<int> &arr, int i, int pvt) {
  if (pvt - i != 0) {
    int partition = partitioner(arr, i - 1, pvt);

    QuickSort(arr, i, partition-1);
  }
}

int main() {

  vector<int> my_array = {20, 2, 7, 12, 15, 1, 6, 8};
  // Call quicksort function

  // Print sorted array
  cout << "Sorted array: ";
  for (int num : my_array) {
    cout << num << " ";
  }

  return 0;
}
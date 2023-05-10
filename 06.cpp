#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomizedPartition(vector<int>& arr, int low, int high) {
    srand(time(0));
    int random = low + rand() % (high - low + 1);
    swap(arr[random], arr[high]);
    return partition(arr, low, high);
}

int randomizedSelect(vector<int>& arr, int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivotIndex = randomizedPartition(arr, low, high);
    int length = pivotIndex - low + 1;

    if (k == length) {
        return arr[pivotIndex];
    } else if (k < length) {
        return randomizedSelect(arr, low, pivotIndex - 1, k);
    } else {
        return randomizedSelect(arr, pivotIndex + 1, high, k - length);
    }
}

int main() {
    vector<int> arr = {3, 7, 2, 9, 1, 5, 6, 8, 4};
    int k = 5; // k-th smallest element

    int result = randomizedSelect(arr, 0, arr.size() - 1, k);
    cout << "The k-th smallest element is: " << result << endl;

    return 0;
}

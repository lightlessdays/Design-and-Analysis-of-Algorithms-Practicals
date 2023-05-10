#include <iostream>
#include <vector>
#include <random>

using namespace std;

int partition(vector<int>& arr, int low, int high, long long& comparisons) {
    // Select a random pivot index
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(low, high);
    int pivotIndex = dis(gen);

    // Swap pivot with the last element
    swap(arr[pivotIndex], arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            comparisons++;
        }
    }

    swap(arr[i + 1], arr[high]);
    comparisons++;

    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, long long& comparisons) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, comparisons);

        quickSort(arr, low, pivotIndex - 1, comparisons);
        quickSort(arr, pivotIndex + 1, high, comparisons);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long comparisons = 0;
    quickSort(arr, 0, n - 1, comparisons);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << "\n";

    cout << "Number of comparisons made: " << comparisons << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

// Function to heapify a subtree rooted at 'rootIndex'
// n is the size of the heap
// compCount is the reference to the comparison count
void heapify(vector<int>& arr, int n, int rootIndex, int& compCount) {
    int largest = rootIndex;  // Initialize largest as root
    int left = 2 * rootIndex + 1;  // Left child
    int right = 2 * rootIndex + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != rootIndex) {
        swap(arr[rootIndex], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest, compCount);
        compCount += 1;  // Increment the comparison count
    }
}

// Main function to perform heap sort
// arr is the array to be sorted
// compCount is the reference to the comparison count
void heapSort(vector<int>& arr, int& compCount) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, compCount);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0, compCount);
        compCount += 1;  // Increment the comparison count
    }
}

int main() {
    int numElements;
    cout << "Enter the number of elements: ";
    cin >> numElements;

    vector<int> elements(numElements);
    cout << "Enter the elements: ";
    for (int i = 0; i < numElements; i++) {
        cin >> elements[i];
    }

    int comparisonCount = 0;
    heapSort(elements, comparisonCount);

    cout << "Sorted array: ";
    for (int i = 0; i < numElements; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;

    cout << "Number of comparisons: " << comparisonCount << endl;

    return 0;
}

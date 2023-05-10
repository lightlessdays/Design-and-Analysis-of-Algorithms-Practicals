#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform insertion sort on a bucket
void insertionSort(std::vector<int>& bucket) {
    int n = bucket.size();
    for (int i = 1; i < n; i++) {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Bucket Sort function
void bucketSort(std::vector<int>& arr, int n) {
    // Create empty buckets
    std::vector<std::vector<int>> buckets(n);

    // Put elements into respective buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++)
        insertionSort(buckets[i]);

    // Concatenate all buckets into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

int main() {
    int numValues;
    std::cout << "Enter the number of values: ";
    std::cin >> numValues;

    std::vector<int> arr(numValues);
    std::cout << "Enter the values:\n";
    for (int i = 0; i < numValues; i++)
        std::cin >> arr[i];

    bucketSort(arr, numValues);

    std::cout << "Sorted array: ";
    for (int i = 0; i < numValues; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}

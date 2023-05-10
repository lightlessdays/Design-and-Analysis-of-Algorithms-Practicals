#include <iostream>
#include <vector>

// Function to find the maximum element in the array
int findMax(std::vector<int>& arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Using counting sort to sort the elements based on the place value
void countingSort(std::vector<int>& arr, int n, int exp) {
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] contains the actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[] so that arr[] contains
    // sorted numbers according to the current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort function
void radixSort(std::vector<int>& arr, int n) {
    // Find the maximum number to determine the number of digits
    int max = findMax(arr, n);

    // Perform counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int numValues;
    std::cout << "Enter the number of values: ";
    std::cin >> numValues;

    std::vector<int> arr(numValues);
    std::cout << "Enter the values:\n";
    for (int i = 0; i < numValues; i++)
        std::cin >> arr[i];

    radixSort(arr, numValues);

    std::cout << "Sorted array: ";
    for (int i = 0; i < numValues; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}

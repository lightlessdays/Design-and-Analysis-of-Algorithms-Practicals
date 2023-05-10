#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    long long comparisons = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        comparisons++;
    }

    while (i < n1) {
        arr[k++] = L[i++];
        comparisons++;
    }

    while (j < n2) {
        arr[k++] = R[j++];
        comparisons++;
    }

    return comparisons;
}

long long mergeSort(vector<int>& arr, int left, int right) {
    long long comparisons = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        comparisons += mergeSort(arr, left, mid);
        comparisons += mergeSort(arr, mid + 1, right);

        comparisons += merge(arr, left, mid, right);
    }
    return comparisons;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long comparisons = mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << "\n";

    cout << "Number of comparisons made: " << comparisons << endl;

    return 0;
}

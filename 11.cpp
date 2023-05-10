#include <iostream>
#include <vector>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to solve the 0-1 Knapsack problem
int knapsack(int W, const vector<Item>& items) {
    int n = items.size();

    // Create a 2D table to store the computed results
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            // If the current item's weight is less than or equal to the remaining capacity
            if (items[i - 1].weight <= w) {
                // Compute the maximum value by considering or not considering the current item
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            } else {
                // If the current item's weight is more than the remaining capacity,
                // just copy the value from the previous row
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Return the maximum value that can be achieved
    return dp[n][W];
}

int main() {
    int W; // Total weight capacity of the knapsack
    int n; // Number of items

    cout << "Enter the total weight capacity of the knapsack: ";
    cin >> W;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ":\n";
        cout << "Weight: ";
        cin >> items[i].weight;
        cout << "Value: ";
        cin >> items[i].value;
        cout << endl;
    }

    int maxValue = knapsack(W, items);
    cout << "The maximum value that can be achieved: " << maxValue << endl;

    return 0;
}

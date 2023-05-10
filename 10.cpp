#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an interval
struct Interval {
    int start;
    int end;
    int weight;
};

// Function to compare intervals based on their end times
bool compareIntervals(const Interval& a, const Interval& b) {
    return a.end < b.end;
}

// Function to find the latest non-conflicting interval
int findLatestNonConflicting(const vector<Interval>& intervals, int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (intervals[j].end <= intervals[i].start) {
            return j;
        }
    }
    return -1;
}

// Function to solve the weighted interval scheduling problem
int weightedIntervalScheduling(const vector<Interval>& intervals) {
    int n = intervals.size();

    // Sort the intervals based on their end times
    vector<Interval> sortedIntervals = intervals;
    sort(sortedIntervals.begin(), sortedIntervals.end(), compareIntervals);

    // Create a table to store the computed results
    vector<int> dp(n, 0);

    dp[0] = sortedIntervals[0].weight;

    // Build the table in a bottom-up manner
    for (int i = 1; i < n; i++) {
        int weightIncludingInterval = sortedIntervals[i].weight;
        int latestNonConflicting = findLatestNonConflicting(sortedIntervals, i);
        if (latestNonConflicting != -1) {
            weightIncludingInterval += dp[latestNonConflicting];
        }
        dp[i] = max(weightIncludingInterval, dp[i - 1]);
    }

    // Return the maximum weight that can be achieved
    return dp[n - 1];
}

int main() {
    int n; // Number of intervals

    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<Interval> intervals(n);

    cout << "Enter the start time, end time, and weight of each interval:\n";
    for (int i = 0; i < n; i++) {
        cout << "Interval " << i + 1 << ":\n";
        cout << "Start time: ";
        cin >> intervals[i].start;
        cout << "End time: ";
        cin >> intervals[i].end;
        cout << "Weight: ";
        cin >> intervals[i].weight;
        cout << endl;
    }

    int maxWeight = weightedIntervalScheduling(intervals);
    cout << "The maximum weight that can be achieved: " << maxWeight << endl;

    return 0;
}

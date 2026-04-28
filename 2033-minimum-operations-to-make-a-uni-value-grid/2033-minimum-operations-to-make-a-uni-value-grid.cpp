#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;

        // Flatten grid
        for (auto &row : grid) {
            for (int val : row) {
                arr.push_back(val);
            }
        }

        // Check feasibility
        int base = arr[0];
        for (int val : arr) {
            if ((val - base) % x != 0) {
                return -1;
            }
        }

        // Sort array
        sort(arr.begin(), arr.end());

        // Median
        int median = arr[arr.size() / 2];

        // Count operations
        int operations = 0;
        for (int val : arr) {
            operations += abs(val - median) / x;
        }

        return operations;
    }
};
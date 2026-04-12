#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dist(int a, int b) {
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int minimumDistance(string word) {
        int n = word.size();
        
        vector<int> dp(26, 0); // max saving
        int total = 0;

        for (int i = 1; i < n; i++) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';

            int best = 0;

            for (int j = 0; j < 26; j++) {
                // Try moving second finger from j → cur
                dp[prev] = max(dp[prev], dp[j] + dist(prev, cur) - dist(j, cur));
            }

            total += dist(prev, cur);
        }

        int maxSave = 0;
        for (int i = 0; i < 26; i++) {
            maxSave = max(maxSave, dp[i]);
        }

        return total - maxSave;
    }
};
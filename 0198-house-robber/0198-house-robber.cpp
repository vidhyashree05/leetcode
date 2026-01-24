class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0; // dp[i-2]
        int prev2 = 0; // dp[i-1]

        for (int money : nums) {
            int curr = max(prev2, prev1 + money);
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};

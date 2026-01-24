class Solution {
public:
    int robLine(vector<int>& nums, int l, int r) {
        int prev1 = 0, prev2 = 0;

        for (int i = l; i <= r; i++) {
            int curr = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        return max(
            robLine(nums, 0, n - 2),
            robLine(nums, 1, n - 1)
        );
    }
};

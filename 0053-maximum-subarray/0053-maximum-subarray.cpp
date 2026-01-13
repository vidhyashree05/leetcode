class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxSum = nums[0]; // stores max subarray sum
        int currentSum = nums[0]; // stores sum ending at current index

        for (int i = 1; i < nums.size(); i++) {
            // Either start new subarray at nums[i] or extend current subarray
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

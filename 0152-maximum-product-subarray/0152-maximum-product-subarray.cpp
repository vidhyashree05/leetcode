class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int curMax = nums[0];
        int curMin = nums[0];
        int result = nums[0];

        for (int i = 1; i < n; i++) {

            // If number is negative, swap max and min
            if (nums[i] < 0)
                swap(curMax, curMin);

            // Update current max and min
            curMax = max(nums[i], curMax * nums[i]);
            curMin = min(nums[i], curMin * nums[i]);

            // Update global result
            result = max(result, curMax);
        }

        return result;
    }
};

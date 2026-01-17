class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int x : nums)
            totalSum += x;

        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == totalSum - leftSum - nums[i])
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};

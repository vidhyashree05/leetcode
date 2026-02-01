class Solution {
public:
    int minimumCost(vector<int>& nums) {
        vector<int> rest(nums.begin() + 1, nums.end());
        sort(rest.begin(), rest.end());
        return nums[0] + rest[0] + rest[1];
    }
};

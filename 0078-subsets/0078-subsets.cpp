class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(0, nums, curr, res);
        return res;
    }

    void backtrack(int idx, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res) {
        if (idx == nums.size()) {
            res.push_back(curr);
            return;
        }

        backtrack(idx + 1, nums, curr, res);

        curr.push_back(nums[idx]);
        backtrack(idx + 1, nums, curr, res);
        curr.pop_back();
    }
};

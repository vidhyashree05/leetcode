class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtrack(int start, vector<int>& nums) {
        result.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates at the same level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            path.push_back(nums[i]);
            backtrack(i + 1, nums);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // MUST
        backtrack(0, nums);
        return result;
    }
};

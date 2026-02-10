class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s) {
            // start of a sequence
            if (!s.count(num - 1)) {
                int curr = num;
                int count = 1;

                while (s.count(curr + 1)) {
                    curr++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};

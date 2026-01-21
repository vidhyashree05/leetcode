class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;   // sum 0 at index -1

        int sum = 0, maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 1) ? 1 : -1;

            if (mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }

        return maxLen;
    }
};

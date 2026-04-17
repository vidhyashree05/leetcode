class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            // Check if current number matches reverse of previous
            if (mp.count(nums[i])) {
                ans = min(ans, i - mp[nums[i]]);
            }

            // Store reverse of current number
            int rev = reverseNum(nums[i]);
            mp[rev] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
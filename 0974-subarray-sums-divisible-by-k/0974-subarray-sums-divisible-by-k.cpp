class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;  // to handle subarrays starting from index 0

        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;
            int rem = sum % k;
            
            // handle negative remainder
            if (rem < 0)
                rem += k;

            if (mp.find(rem) != mp.end())
                count += mp[rem];

            mp[rem]++;
        }
        return count;
    }
};

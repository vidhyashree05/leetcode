class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                res[i] = 0;
            } else {
                int j = (i + nums[i]) % n;
                if (j < 0) j += n;   
                res[i] = nums[j];
            }
        }
        return res;
    }
};

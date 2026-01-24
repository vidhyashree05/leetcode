class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int pieces = 1;
        long long currSum = 0;

        for (int x : nums) {
            if (currSum + x > maxSum) {
                pieces++;
                currSum = x;
                if (pieces > k) return false;
            } else {
                currSum += x;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for (int x : nums) high += x;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};

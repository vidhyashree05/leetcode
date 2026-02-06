class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        // Step 1: Sort the array so min and max are easy to track
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Left pointer of sliding window
        int left = 0;

        // Stores the maximum number of elements we can keep balanced
        int maxKeep = 1;  // At least one element is always balanced

        // Step 2: Expand the window using right pointer
        for (int right = 0; right < n; right++) {

            // Step 3: Shrink window if condition is violated
            // max element = nums[right]
            // min element = nums[left]
            while ((long long)nums[right] > (long long)nums[left] * k) {
                left++;  // Move left to reduce the range
            }

            // Step 4: Update maximum valid window size
            maxKeep = max(maxKeep, right - left + 1);
        }

        // Step 5: Minimum removals = total elements - elements kept
        return n - maxKeep;
    }
};

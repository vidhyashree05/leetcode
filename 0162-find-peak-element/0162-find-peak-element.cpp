class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Ascending → peak on right
                left = mid + 1;
            } else {
                // Descending → peak on left (including mid)
                right = mid;
            }
        }

        return left;  // or right (both same)
    }
};

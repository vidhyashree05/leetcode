class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
        // Ordered set (balanced BST)
        // Use long to prevent overflow
        multiset<long> window;
        
        for (int i = 0; i < nums.size(); i++) {
            
            long current = nums[i];
            
            // Find first element >= (current - valueDiff)
            auto it = window.lower_bound(current - valueDiff);
            
            // Check if such element exists AND
            // it is within allowed valueDiff range
            if (it != window.end() && abs(*it - current) <= valueDiff) {
                return true;
            }
            
            // Insert current number into window
            window.insert(current);
            
            // Maintain sliding window size ≤ indexDiff
            if (window.size() > indexDiff) {
                window.erase(window.find(nums[i - indexDiff]));
            }
        }
        
        return false;
    }
};
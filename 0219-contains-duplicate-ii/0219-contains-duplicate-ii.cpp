class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        // This unordered_set will act as a sliding window
        // It will store at most k previous elements
        unordered_set<int> window;
        
        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {
            
            // Step 1: If current number already exists in window,
            // that means we found a duplicate within distance k
            if (window.count(nums[i])) {
                return true;
            }
            
            // Step 2: Insert current number into window
            window.insert(nums[i]);
            
            // Step 3: Maintain window size ≤ k
            // If size becomes greater than k,
            // remove the element that is k positions behind
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        
        // If no valid duplicate found
        return false;
    }
};
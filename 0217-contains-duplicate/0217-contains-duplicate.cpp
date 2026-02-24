class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        // Create an unordered_set to store seen elements
        unordered_set<int> seen;
        
        // Traverse the array
        for (int num : nums) {
            
            // If number already exists in set → duplicate found
            if (seen.count(num)) {
                return true;
            }
            
            // Otherwise insert it into the set
            seen.insert(num);
        }
        
        // If no duplicates found
        return false;
    }
};
class Solution {
public:
    int trailingZeroes(int n) {
        
        int count = 0;   // To store number of trailing zeroes
        
        // Keep dividing n by 5, 25, 125, ...
        while (n > 0) {
            n = n / 5;      // Count multiples of 5
            count += n;     // Add to total count
        }
        
        return count;   // Return total trailing zeroes
    }
};

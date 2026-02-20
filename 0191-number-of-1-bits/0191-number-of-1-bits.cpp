class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while (n > 0) {
            count += (n & 1);  // Check last bit
            n = n >> 1;       // Right shift
        }
        
        return count;
    }
};
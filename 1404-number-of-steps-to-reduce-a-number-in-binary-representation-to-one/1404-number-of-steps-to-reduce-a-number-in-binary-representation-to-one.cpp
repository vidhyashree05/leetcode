class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        // Traverse from last bit to second bit
        for (int i = s.length() - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;
            
            if (bit == 1) {
                // odd case: add 1 + divide by 2
                steps += 2;
                carry = 1;
            } else {
                // even case: just divide by 2
                steps += 1;
                // carry stays same if bit == 2
            }
        }
        
        // If carry remains after processing
        return steps + carry;
    }
};
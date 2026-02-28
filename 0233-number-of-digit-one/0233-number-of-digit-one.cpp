class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;      // To store final answer
        long long factor = 1;     // 1, 10, 100, 1000...
        
        while (factor <= n) {
            
            // Split number into three parts
            long long lower = n % factor;                     
            long long current = (n / factor) % 10;            
            long long higher = n / (factor * 10);             
            
            // Case 1: Current digit is 0
            if (current == 0) {
                count += higher * factor;
            }
            // Case 2: Current digit is 1
            else if (current == 1) {
                count += higher * factor + lower + 1;
            }
            // Case 3: Current digit > 1
            else {
                count += (higher + 1) * factor;
            }
            
            // Move to next digit position
            factor *= 10;
        }
        
        return count;
    }
};
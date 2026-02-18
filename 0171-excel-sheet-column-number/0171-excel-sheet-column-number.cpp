class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        long long result = 0;   // This will store the final column number
        
        // Loop through each character in the string
        for(char c : columnTitle) {
            
            // Multiply previous result by 26 (like base-26 number system)
            result = result * 26;
            
            // Convert current character to its position value:
            // 'A' -> 1
            // 'B' -> 2
            // ...
            // 'Z' -> 26
            result = result + (c - 'A' + 1);
        }
        
        return result;   // Return final column number
    }
};

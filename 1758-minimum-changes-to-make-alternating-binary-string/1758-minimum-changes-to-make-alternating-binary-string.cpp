class Solution {
public:
    int minOperations(string s) {
        int mismatch1 = 0; // pattern 0101...
        int mismatch2 = 0; // pattern 1010...

        for(int i = 0; i < s.length(); i++) {
            if(i % 2 == 0) {
                if(s[i] != '0') mismatch1++;
                if(s[i] != '1') mismatch2++;
            }
            else {
                if(s[i] != '1') mismatch1++;
                if(s[i] != '0') mismatch2++;
            }
        }

        return min(mismatch1, mismatch2);
    }
};
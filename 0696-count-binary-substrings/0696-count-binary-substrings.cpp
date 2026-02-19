class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevGroup = 0;      // previous group length
        int currGroup = 1;      // current group length
        int result = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                currGroup++;  // same character, increase current group
            } else {
                result += min(prevGroup, currGroup);
                prevGroup = currGroup;
                currGroup = 1;
            }
        }

        // Add last comparison
        result += min(prevGroup, currGroup);

        return result;
    }
};

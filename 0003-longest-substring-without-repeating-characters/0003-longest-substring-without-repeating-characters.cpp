class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1); // stores last index of characters
        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            if (last[s[i]] >= start) {
                start = last[s[i]] + 1;
            }
            last[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};

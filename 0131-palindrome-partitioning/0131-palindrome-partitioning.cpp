class Solution {
public:
    vector<vector<string>> result;

    // Function to check if substring is palindrome
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    // Backtracking function
    void backtrack(string &s, int start, vector<string> &path) {
        // If we reached end of string
        if (start == s.length()) {
            result.push_back(path);
            return;
        }

        // Try all possible partitions
        for (int end = start; end < s.length(); end++) {

            // If substring is palindrome
            if (isPalindrome(s, start, end)) {
                
                // Choose substring
                path.push_back(s.substr(start, end - start + 1));

                // Recurse for remaining string
                backtrack(s, end + 1, path);

                // Backtrack
                path.pop_back();
            }
        }
    }

    // Required function name for LeetCode
    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(s, 0, path);
        return result;
    }
};

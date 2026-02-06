class Solution {
public:
    vector<string> result;

    // Backtracking function
    void backtrack(string &s, int index, int parts, string curr) {

        // If we used 4 parts and consumed the whole string
        if (parts == 4 && index == s.size()) {
            curr.pop_back();          // remove last '.'
            result.push_back(curr);
            return;
        }

        // If parts exceed 4 or index goes out of range
        if (parts == 4 || index >= s.size())
            return;

        int num = 0;

        // Try taking 1 to 3 digits
        for (int i = index; i < s.size() && i < index + 3; i++) {

            num = num * 10 + (s[i] - '0');

            // If value exceeds 255 → invalid
            if (num > 255)
                break;

            // Leading zero check
            if (i > index && s[index] == '0')
                break;

            // Recurse with one more part
            backtrack(s, i + 1, parts + 1, curr + s.substr(index, i - index + 1) + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return result;
    }
};

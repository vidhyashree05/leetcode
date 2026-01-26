class Solution {
public:
    vector<string> result;
    vector<string> mapping = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return result;
        backtrack(digits, 0, "");
        return result;
    }

    void backtrack(string& digits, int index, string curr) {
        if (index == digits.size()) {
            result.push_back(curr);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            backtrack(digits, index + 1, curr + c);
        }
    }
};

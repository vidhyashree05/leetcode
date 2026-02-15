class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        // Extract words (automatically removes extra spaces)
        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse words
        reverse(words.begin(), words.end());

        // Join with single space
        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1)
                result += " ";
        }

        return result;
    }
};

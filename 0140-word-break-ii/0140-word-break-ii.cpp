class Solution {
public:
    unordered_map<string, vector<string>> memo;
    unordered_set<string> dict;

    vector<string> dfs(string s) {
        if (memo.count(s)) 
            return memo[s];

        vector<string> result;

        if (s.empty()) {
            result.push_back("");
            return result;
        }

        for (int i = 1; i <= s.size(); i++) {
            string prefix = s.substr(0, i);

            if (dict.count(prefix)) {
                string suffix = s.substr(i);
                vector<string> suffixWays = dfs(suffix);

                for (string &way : suffixWays) {
                    result.push_back(
                        prefix + (way.empty() ? "" : " " + way)
                    );
                }
            }
        }

        memo[s] = result;
        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s);
    }
};

class Solution {
public:
    unordered_map<string, vector<string>> parent;
    unordered_map<string, int> dist;
    vector<vector<string>> result;
    string begin;

    void dfs(string word, vector<string>& path) {
        if (word == begin) {
            reverse(path.begin(), path.end());
            result.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (auto &p : parent[word]) {
            if (dist[p] + 1 == dist[word]) {
                path.push_back(p);
                dfs(p, path);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        begin = beginWord;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;

        int L = beginWord.length();

        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            int steps = dist[curr];

            string temp = curr;
            for (int i = 0; i < L; i++) {
                char original = temp[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == original) continue;
                    temp[i] = c;

                    if (dict.count(temp)) {
                        if (!dist.count(temp)) {
                            dist[temp] = steps + 1;
                            q.push(temp);
                        }
                        // store correct parent
                        parent[temp].push_back(curr);
                    }
                }
                temp[i] = original;
            }
        }

        vector<string> path = {endWord};
        dfs(endWord, path);

        return result;
    }
};


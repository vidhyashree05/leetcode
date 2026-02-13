class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;

        // Case 1: single character (continuous block)
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            res = max(res, j - i);
            i = j;
        }

        // Case 2: two characters equal count
        vector<pair<char,char>> pairs = {
            {'a','b'}, {'a','c'}, {'b','c'}
        };

        for (auto [x, y] : pairs) {
            unordered_map<int,int> mp;
            mp[0] = -1;
            int diff = 0;

            for (int i = 0; i < n; i++) {
                if (s[i] == x) diff++;
                else if (s[i] == y) diff--;
                else {
                    diff = 0;
                    mp.clear();
                    mp[0] = i;
                    continue;
                }

                if (mp.count(diff)) {
                    res = max(res, i - mp[diff]);
                } else {
                    mp[diff] = i;
                }
            }
        }

        // Case 3: all three equal
        unordered_map<long long,int> mp;
        auto encode = [](int x, int y) {
            return ((long long)x << 32) | (unsigned int)y;
        };

        int a = 0, b = 0, c = 0;
        mp[encode(0,0)] = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else c++;

            long long key = encode(a-b, a-c);

            if (mp.count(key)) {
                res = max(res, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }

        return res;
    }
};

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int len = n + m - 1;

        string res(len, '?');

        // Step 1: Apply 'T'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (res[i + j] == '?' || res[i + j] == str2[j]) {
                        res[i + j] = str2[j];
                    } else {
                        return "";
                    }
                }
            }
        }

        // Step 2: Fill remaining greedily
        for (int i = 0; i < len; i++) {
            if (res[i] == '?') {
                for (char c = 'a'; c <= 'z'; c++) {
                    res[i] = c;

                    bool ok = true;

                    // check all substrings covering i
                    for (int start = max(0, i - m + 1); start <= min(i, n - 1); start++) {
                        bool match = true;
                        for (int k = 0; k < m; k++) {
                            if (res[start + k] != str2[k]) {
                                match = false;
                                break;
                            }
                        }

                        if (str1[start] == 'T' && !match) ok = false;
                        if (str1[start] == 'F' && match) ok = false;

                        if (!ok) break;
                    }

                    if (ok) break;
                }
            }
        }

        // Step 3: Final validation
        for (int i = 0; i < n; i++) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (res[i + j] != str2[j]) {
                    match = false;
                    break;
                }
            }
            if ((str1[i] == 'T' && !match) || (str1[i] == 'F' && match))
                return "";
        }

        return res;
    }
};
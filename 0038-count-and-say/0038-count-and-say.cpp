#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 2; i <= n; i++) {
            string next = "";
            for (int j = 0; j < s.size(); j++) {
                int count = 1;
                while (j + 1 < s.size() && s[j] == s[j + 1]) {
                    count++;
                    j++;
                }
                next += to_string(count) + s[j];
            }
            s = next;
        }
        return s;
    }
};

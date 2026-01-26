class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long long ans = 0;

        while (i < s.size() && s[i] == ' ') i++;

        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < s.size() && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            if (sign * ans >= INT_MAX) return INT_MAX;
            if (sign * ans <= INT_MIN) return INT_MIN;

            i++;
        }

        return sign * ans;
    }
};

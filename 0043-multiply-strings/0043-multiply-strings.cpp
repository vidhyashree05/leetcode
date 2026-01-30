#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        if (num1 == "0" || num2 == "0") return "0";

        vector<int> result(n1 + n2, 0);

        // Multiply each digit
        for (int i = n1 - 1; i >= 0; i--) {
            int a = num1[i] - '0';
            for (int j = n2 - 1; j >= 0; j--) {
                int b = num2[j] - '0';
                int sum = result[i + j + 1] + a * b;
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        // Convert to string
        string res;
        int i = 0;
        while (i < result.size() && result[i] == 0) i++; // skip leading zeros
        for (; i < result.size(); i++) res += result[i] + '0';

        return res.empty() ? "0" : res;
    }
};

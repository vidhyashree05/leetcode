class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        // Store all prefixes from arr1
        for (int num : arr1) {
            while (num > 0) {
                prefixes.insert(num);
                num /= 10;
            }
        }

        int ans = 0;

        // Check prefixes of arr2 numbers
        for (int num : arr2) {
            int temp = num;

            while (temp > 0) {
                if (prefixes.count(temp)) {
                    ans = max(ans, (int)to_string(temp).size());
                }
                temp /= 10;
            }
        }

        return ans;
    }
};
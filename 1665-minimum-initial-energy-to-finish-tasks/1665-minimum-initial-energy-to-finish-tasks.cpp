class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        // Sort by (minimum - actual) descending
        sort(tasks.begin(), tasks.end(),
             [](vector<int>& a, vector<int>& b) {
                 return (a[1] - a[0]) > (b[1] - b[0]);
             });

        int ans = 0;      // minimum initial energy needed
        int curr = 0;     // current energy while simulating

        for (auto &t : tasks) {
            int actual = t[0];
            int minimum = t[1];

            // If current energy is less than required minimum,
            // add extra energy to initial answer
            if (curr < minimum) {
                ans += (minimum - curr);
                curr = minimum;
            }

            // Complete the task
            curr -= actual;
        }

        return ans;
    }
};
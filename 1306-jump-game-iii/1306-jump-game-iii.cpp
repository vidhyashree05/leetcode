class Solution {
public:
    bool dfs(vector<int>& arr, int i, vector<int>& vis) {
        int n = arr.size();

        // outside array
        if (i < 0 || i >= n || vis[i])
            return false;

        // reached zero
        if (arr[i] == 0)
            return true;

        vis[i] = 1;

        return dfs(arr, i + arr[i], vis) ||
               dfs(arr, i - arr[i], vis);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);
        return dfs(arr, start, vis);
    }
};
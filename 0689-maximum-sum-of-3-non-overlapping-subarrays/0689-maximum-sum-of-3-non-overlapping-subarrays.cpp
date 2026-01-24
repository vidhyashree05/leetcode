class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(4, {INT_MIN,-1}));
        for(int i=0; i<n; i++)
            dp[i][0] = {0,0};
        vector<int> pref(n, 0);
        pref[0] = nums[0];
        for(int i=1; i<n; i++)
            pref[i] = nums[i] + pref[i-1];
        for(int i=k-1; i<n; i++){
            if(i+1>=k)
                dp[i][1] = max((i-1>=0?dp[i-1][1]:(pair<int,int>){INT_MIN, -1}), pair<int,int>{(i-k>=0?dp[i-k][0].first:0) + (pref[i]-(i-k>=0?pref[i-k]:0)), -(i-k+1)});
            if((i+1) >= 2*k)
                dp[i][2] = max((i-1>=0?dp[i-1][2]:(pair<int,int>){INT_MIN, -1}), pair<int,int>{(i-k>=0?dp[i-k][1].first:0) + (pref[i]-(i-k>=0?pref[i-k]:0)), -(i-k+1)});
            if((i+1) >= 3*k)
                dp[i][3] = max((i-1>=0?dp[i-1][3]:(pair<int,int>){INT_MIN, -1}), pair<int,int>{(i-k>=0?dp[i-k][2].first:0) + (pref[i]-(i-k>=0?pref[i-k]:0)), -(i-k+1)});
        }
        int f = -dp[n-1][3].second;
        int s = -dp[f-1][2].second;
        int t = -dp[s-1][1].second;
        vector<int> ans={f,s,t};
        sort(ans.begin(), ans.end());
        return ans;

    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(
        string source, string target,
        vector<string>& original, vector<string>& changed,
        vector<int>& cost
    ) {
        const long long INF = 1e18;
        int n = source.size();

        // Step 1: Map every string to an id
        unordered_map<string,int> mp;
        int idx = 0;
        auto getId = [&](const string &s){
            if(!mp.count(s)) mp[s] = idx++;
            return mp[s];
        };

        for(auto &s: original) getId(s);
        for(auto &s: changed) getId(s);

        int m = idx;
        vector<vector<long long>> dist(m, vector<long long>(m, INF));
        for(int i=0;i<m;i++) dist[i][i]=0;

        for(int i=0;i<original.size();i++){
            int u = mp[original[i]];
            int v = mp[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd-Warshall for chaining
        for(int k=0;k<m;k++)
            for(int i=0;i<m;i++)
                for(int j=0;j<m;j++)
                    if(dist[i][k]<INF && dist[k][j]<INF)
                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

        // Step 2: Prepare mapping of length -> original indices
        unordered_map<int, vector<int>> len2idx;
        for(int i=0;i<original.size();i++)
            len2idx[original[i].size()].push_back(i);

        // Step 3: DP
        vector<long long> dp(n+1, INF);
        dp[0] = 0;

        for(int i=0;i<n;i++){
            if(dp[i]==INF) continue;

            // Option 1: match single character
            if(source[i]==target[i])
                dp[i+1] = min(dp[i+1], dp[i]);

            // Option 2: apply transformations
            for(auto &[len, ids]: len2idx){
                if(i+len>n) continue;
                string sub = source.substr(i,len);
                string targ = target.substr(i,len);

                for(int id_orig: ids){
                    if(sub != original[id_orig]) continue;

                    int u = mp[original[id_orig]];
                    // Only continue if targ is in mp
                    if(!mp.count(targ)) continue;
                    int v = mp[targ];

                    long long c = dist[u][v];
                    if(c<INF){
                        dp[i+len] = min(dp[i+len], dp[i]+c);
                    }
                }
            }
        }

        return dp[n]==INF ? -1 : dp[n];
    }
};

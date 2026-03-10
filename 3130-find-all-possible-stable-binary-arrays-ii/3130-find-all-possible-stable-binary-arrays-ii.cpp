class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        
        const int MOD = 1e9 + 7;

        // dp memo table
        vector<vector<vector<int>>> dpMemo(
            zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));

        function<int(int,int,int)> solve = [&](int z, int o, int last) {

            // base cases
            if(z == 0){
                if(last == 0 || o > limit) return 0;
                return 1;
            }

            if(o == 0){
                if(last == 1 || z > limit) return 0;
                return 1;
            }

            if(dpMemo[z][o][last] != -1)
                return dpMemo[z][o][last];

            long long ways = 0;

            if(last == 0){
                // place zero
                ways = (solve(z-1, o, 0) + solve(z-1, o, 1)) % MOD;

                if(z > limit){
                    ways = (ways - solve(z-limit-1, o, 1) + MOD) % MOD;
                }
            }
            else{
                // place one
                ways = (solve(z, o-1, 0) + solve(z, o-1, 1)) % MOD;

                if(o > limit){
                    ways = (ways - solve(z, o-limit-1, 0) + MOD) % MOD;
                }
            }

            return dpMemo[z][o][last] = ways % MOD;
        };

        return (solve(zero, one, 0) + solve(zero, one, 1)) % MOD;
    }
};
class Solution {
public:
    const int MOD = 1e9 + 7;

    int dp[201][201][2][201];

    int solve(int z, int o, int last, int cnt, int zero, int one, int limit) {
        if (z > zero || o > one) return 0;

        if (z == zero && o == one) return 1;

        if (dp[z][o][last][cnt] != -1)
            return dp[z][o][last][cnt];

        long long ans = 0;

        // place 0
        if (z < zero) {
            if (last == 0) {
                if (cnt + 1 <= limit)
                    ans += solve(z + 1, o, 0, cnt + 1, zero, one, limit);
            } else {
                ans += solve(z + 1, o, 0, 1, zero, one, limit);
            }
        }

        // place 1
        if (o < one) {
            if (last == 1) {
                if (cnt + 1 <= limit)
                    ans += solve(z, o + 1, 1, cnt + 1, zero, one, limit);
            } else {
                ans += solve(z, o + 1, 1, 1, zero, one, limit);
            }
        }

        return dp[z][o][last][cnt] = ans % MOD;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));

        long long ans = 0;

        if (zero > 0)
            ans += solve(1, 0, 0, 1, zero, one, limit);

        if (one > 0)
            ans += solve(0, 1, 1, 1, zero, one, limit);

        return ans % MOD;
    }
};
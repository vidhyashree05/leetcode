#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlace(vector<long long>& pos, int n, int k, long long d, long long per) {
        vector<int> next(2 * n);

        int j = 0;
        for (int i = 0; i < 2 * n; i++) {
            while (j < 2 * n && pos[j] - pos[i] < d) j++;
            next[i] = j;
        }

        for (int i = 0; i < n; i++) {
            int count = 1;
            int cur = i;

            while (count < k) {
                cur = next[cur];
                if (cur >= i + n) break;
                count++;
            }

            if (count == k) {
                if (per - (pos[cur] - pos[i]) >= d)
                    return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> pos;

        // map to perimeter
        for (auto &p : points) {
            long long x = p[0], y = p[1];

            if (x == 0) pos.push_back(y);
            else if (y == side) pos.push_back(side + x);
            else if (x == side) pos.push_back(3LL * side - y);
            else pos.push_back(4LL * side - x);
        }

        sort(pos.begin(), pos.end());
        int n = pos.size();

        long long per = 4LL * side;

        vector<long long> ext = pos;
        for (int i = 0; i < n; i++) {
            ext.push_back(pos[i] + per);
        }

        long long low = 0, high = 2LL * side, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (canPlace(ext, n, k, mid, per)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};
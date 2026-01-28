#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const long long INF = LLONG_MAX / 4;

        // dist[x][y][t] = min cost to reach (x,y) using t teleports
        vector<vector<vector<long long>>> dist(
            m, vector<vector<long long>>(n, vector<long long>(k + 1, INF))
        );
        dist[0][0][0] = 0;

        // Cells sorted by value for teleport optimization
        vector<tuple<int,int,int>> cells;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cells.emplace_back(grid[i][j], i, j);
        sort(cells.begin(), cells.end());

        vector<int> ptr(k + 1, 0);

        // min-heap: cost, x, y, used teleports
        priority_queue<
            tuple<long long,int,int,int>,
            vector<tuple<long long,int,int,int>>,
            greater<tuple<long long,int,int,int>>
        > pq;

        pq.emplace(0LL, 0, 0, 0);

        while (!pq.empty()) {
            auto [cost, x, y, used] = pq.top();
            pq.pop();

            if (cost > dist[x][y][used]) continue;
            if (x == m - 1 && y == n - 1) return cost;

            // Move down
            if (x + 1 < m) {
                long long nc = cost + grid[x + 1][y];
                if (nc < dist[x + 1][y][used]) {
                    dist[x + 1][y][used] = nc;
                    pq.emplace(nc, x + 1, y, used);
                }
            }

            // Move right
            if (y + 1 < n) {
                long long nc = cost + grid[x][y + 1];
                if (nc < dist[x][y + 1][used]) {
                    dist[x][y + 1][used] = nc;
                    pq.emplace(nc, x, y + 1, used);
                }
            }

            // Teleport
            if (used < k) {
                while (ptr[used] < (int)cells.size() &&
                       get<0>(cells[ptr[used]]) <= grid[x][y]) {
                    int i = get<1>(cells[ptr[used]]);
                    int j = get<2>(cells[ptr[used]]);
                    if (cost < dist[i][j][used + 1]) {
                        dist[i][j][used + 1] = cost;
                        pq.emplace(cost, i, j, used + 1);
                    }
                    ptr[used]++;
                }
            }
        }

        return -1;
    }
};

class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> divisible;

        // Store indices for every divisor
        for (int i = 0; i < n; i++) {
            int x = nums[i];

            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    divisible[d].push_back(i);

                    if (d != x / d)
                        divisible[x / d].push_back(i);
                }
            }
        }

        vector<int> dist(n, -1);
        queue<int> q;

        q.push(0);
        dist[0] = 0;

        unordered_set<int> usedPrime;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1)
                return dist[i];

            // Adjacent moves
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }

            // Prime teleportation
            int p = nums[i];

            if (isPrime(p) && !usedPrime.count(p)) {
                usedPrime.insert(p);

                for (int idx : divisible[p]) {
                    if (dist[idx] == -1) {
                        dist[idx] = dist[i] + 1;
                        q.push(idx);
                    }
                }
            }
        }

        return -1;
    }
};
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        multiset<int> small, large;
        long long sumSmall = 0;

        auto balance = [&]() {
            while ((int)small.size() > k - 1) {
                auto it = prev(small.end());
                sumSmall -= *it;
                large.insert(*it);
                small.erase(it);
            }
            while ((int)small.size() < k - 1 && !large.empty()) {
                auto it = large.begin();
                sumSmall += *it;
                small.insert(*it);
                large.erase(it);
            }
        };

        auto add = [&](int x) {
            if (small.empty() || x <= *prev(small.end())) {
                small.insert(x);
                sumSmall += x;
            } else {
                large.insert(x);
            }
            balance();
        };

        auto remove = [&](int x) {
            if (small.find(x) != small.end()) {
                small.erase(small.find(x));
                sumSmall -= x;
            } else {
                large.erase(large.find(x));
            }
            balance();
        };

        for (int i = 1; i <= dist + 1 && i < n; i++) {
            add(nums[i]);
        }

        long long ans = nums[0] + sumSmall;

        
        for (int i = dist + 2; i < n; i++) {
            add(nums[i]);
            remove(nums[i - (dist + 1)]);
            ans = min(ans, nums[0] + sumSmall);
        }

        return ans;
    }
};

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int, long long>> dq; // index, prefix_sum
        long long sum = 0;
        int shortest = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            sum += nums[i];

            // Check if the current sum itself satisfies the condition
            if (sum >= k) {
                shortest = min(shortest, i + 1); // Subarray from start to i
            }

            // Remove elements from deque that make the subarray sum >= k
            while (!dq.empty() && (sum - dq.front().second >= k)) {
                shortest = min(shortest, i - dq.front().first);
                dq.pop_front();
            }

            // Maintain a monotonic increasing deque (by prefix sum)
            while (!dq.empty() && dq.back().second >= sum) {
                dq.pop_back();
            }

            // Add the current index and sum to the deque
            dq.push_back({i, sum});
        }

        return shortest == INT_MAX ? -1 : shortest;
    }
};
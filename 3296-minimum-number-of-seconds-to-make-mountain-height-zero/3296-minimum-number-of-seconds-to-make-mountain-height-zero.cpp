class Solution {
public:

    // Function to check if workers can reduce the mountain
    // to height 0 within given time T
    bool canFinish(long long T, int mountainHeight, vector<int>& workerTimes) {
        long long totalHeightReduced = 0;

        // Iterate through each worker
        for (long long w : workerTimes) {

            /*
            Time required for worker to reduce height x:

            w * (1 + 2 + 3 + ... + x)
            = w * (x * (x + 1) / 2)

            We need to find maximum x such that:
            w * (x * (x + 1) / 2) <= T

            Solving quadratic equation:
            x ≈ (sqrt(1 + 8T/w) - 1) / 2
            */

            long long x = (sqrt(1 + 8.0 * T / w) - 1) / 2;

            totalHeightReduced += x;

            // If total reduced height is enough, return true
            if (totalHeightReduced >= mountainHeight)
                return true;
        }

        // If workers cannot reduce enough height
        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        /*
        We use Binary Search on the answer (time).

        left  = minimum possible time
        right = very large time (upper bound)
        */

        long long left = 0;
        long long right = 1e18;

        while (left < right) {

            // Mid time to check
            long long mid = left + (right - left) / 2;

            // Check if workers can finish within mid seconds
            if (canFinish(mid, mountainHeight, workerTimes)) {
                // Try to find smaller time
                right = mid;
            } else {
                // Need more time
                left = mid + 1;
            }
        }

        // Minimum time required
        return left;
    }
};
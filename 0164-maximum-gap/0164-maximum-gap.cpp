class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        if (minVal == maxVal) return 0;

        int gap = ceil((double)(maxVal - minVal) / (n - 1));
        int bucketSize = (maxVal - minVal) / gap + 1;

        vector<int> bucketMin(bucketSize, INT_MAX);
        vector<int> bucketMax(bucketSize, INT_MIN);
        vector<bool> used(bucketSize, false);

        // Place elements into buckets
        for (int num : nums) {
            int idx = (num - minVal) / gap;
            bucketMin[idx] = min(bucketMin[idx], num);
            bucketMax[idx] = max(bucketMax[idx], num);
            used[idx] = true;
        }

        // Calculate max gap
        int prevMax = minVal;
        int maxGap = 0;

        for (int i = 0; i < bucketSize; i++) {
            if (!used[i]) continue;

            maxGap = max(maxGap, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }

        return maxGap;
    }
};

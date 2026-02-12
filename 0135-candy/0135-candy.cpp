class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        vector<int> candies(n, 1);  // Step 1: give 1 candy to each child
        
        // Left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        // Right to left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        // Sum all candies
        int total = 0;
        for (int c : candies) {
            total += c;
        }
        
        return total;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        // Traverse prices
        for (int i = 1; i < prices.size(); i++) {
            // If today's price is higher than yesterday
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, buy2 = INT_MIN;
        int sell1 = 0, sell2 = 0;

        for (int price : prices) {
            buy1 = max(buy1, -price);          // first buy
            sell1 = max(sell1, buy1 + price); // first sell
            buy2 = max(buy2, sell1 - price);  // second buy
            sell2 = max(sell2, buy2 + price); // second sell
        }

        return sell2;
    }
};

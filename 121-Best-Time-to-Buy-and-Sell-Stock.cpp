class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }

        int buyDay = 0, sellDay = 1;
        int profit = prices[sellDay] - prices[buyDay];
        int currProfit = profit;

        while (sellDay < prices.size()) {
            currProfit = prices[sellDay] - prices[buyDay];
            if (prices[buyDay] > prices[sellDay]) {
                buyDay = sellDay;
            } else if (currProfit > profit) {
                profit = currProfit;
            }
            sellDay++;
        }

        if (profit < 0) {
            profit = 0;
        }
        return profit;
    }
};
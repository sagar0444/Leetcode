
class Solution {
public:
    int f(int index, int buy, vector<int>& prices,
          int n, vector<vector<int>>& dp) {

        if(index >= n) {
            return 0;
        }

        if(dp[index][buy] != -1) {
            return dp[index][buy];
        }

        int profit = 0;

        if(buy) {
            int take = -prices[index] +
                       f(index+1, 0, prices, n, dp);

            int notTake = f(index+1, 1, prices, n, dp);

            profit = max(take, notTake);
        }
        else {
            int sell = prices[index] +
                       f(index+2, 1, prices, n, dp);

            int notSell = f(index+1, 0, prices, n, dp);

            profit = max(sell, notSell);
        }

        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+2, vector<int>(2, -1));

        return f(0, 1, prices, n, dp);
    }
};

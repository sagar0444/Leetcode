
class Solution {
public:

    int f(int index, int amount, vector<int>& coins,
          vector<vector<int>>& dp) {

        // Base case
        if(index == 0) {
            if(amount % coins[0] == 0) {
                return amount / coins[0];
            }

            return 1e9;
        }

        // Already calculated
        if(dp[index][amount] != -1) {
            return dp[index][amount];
        }

        // Don't pick
        int notPick = f(index - 1, amount, coins, dp);

        // Pick
        int pick = 1e9;

        if(coins[index] <= amount) {
            pick = 1 + f(index, amount - coins[index],
                          coins, dp);
        }

        return dp[index][amount] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(
            n, vector<int>(amount + 1, -1)
        );

        int ans = f(n - 1, amount, coins, dp);

        if(ans >= 1e9) {
            return -1;
        }

        return ans;
    }
};

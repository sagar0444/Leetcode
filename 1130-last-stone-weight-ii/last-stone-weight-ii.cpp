
class Solution {
public:

    bool f(int index, int target, vector<int>& stones,
           vector<vector<int>>& dp) {

        // Base cases
        if(target == 0) {
            return true;
        }

        if(index == 0) {
            return stones[0] == target;
        }

        // Check if already calculated
        if(dp[index][target] != -1) {
            return dp[index][target];
        }

        // Don't pick
        bool notPick = f(index - 1, target, stones, dp);

        // Pick
        bool pick = false;

        if(stones[index] <= target) {
            pick = f(index - 1, target - stones[index],
                      stones, dp);
        }

        // Store and return
        return dp[index][target] = pick || notPick;
    }

    int lastStoneWeightII(vector<int>& stones) {

        int n = stones.size();
        int totalSum = 0;

        for(int x : stones) {
            totalSum += x;
        }

        int target = totalSum / 2;

        vector<vector<int>> dp(
            n, vector<int>(target + 1, -1)
        );

        int best = 0;

        // Find the largest achievable sum <= target
        for(int j = target; j >= 0; j--) {

            if(f(n - 1, j, stones, dp)) {
                best = j;
                break;
            }
        }

        return totalSum - 2 * best;
    }
};

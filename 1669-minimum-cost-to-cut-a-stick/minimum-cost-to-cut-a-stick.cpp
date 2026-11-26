class Solution {
public:

    int f(int i, int j, vector<int>& cuts,
          vector<vector<int>>& dp) {

        // Base case
        if(i > j) {
            return 0;
        }

        // Already calculated
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int mini = INT_MAX;

        // Try every cut as the first cut
        for(int k = i; k <= j; k++) {

            int cost = cuts[j+1] - cuts[i-1]
                       + f(i, k-1, cuts, dp)
                       + f(k+1, j, cuts, dp);

            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {

        sort(cuts.begin(), cuts.end());

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        int m = cuts.size() - 2;

        vector<vector<int>> dp(m+2,
                               vector<int>(m+2, -1));

        return f(1, m, cuts, dp);
    }
};

class Solution {
public:

    int f(int i, int j,
          vector<vector<int>>& matrix,
          vector<vector<int>>& dp,
          vector<vector<bool>>& visited) {

        int n = matrix.size();

        if (j < 0 || j >= n) {
            return 1e9;
        }

        if (i == 0) {
            return matrix[0][j];
        }

        if (visited[i][j]) {
            return dp[i][j];
        }

        visited[i][j] = true;

        int up = matrix[i][j] +
                 f(i-1, j, matrix, dp, visited);

        int left = matrix[i][j] +
                   f(i-1, j-1, matrix, dp, visited);

        int right = matrix[i][j] +
                    f(i-1, j+1, matrix, dp, visited);

        return dp[i][j] = min({up, left, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        int ans = INT_MAX;

        for (int j = 0; j < n; j++) {
            ans = min(ans, f(n-1, j, matrix, dp, visited));
        }

        return ans;
    }
};

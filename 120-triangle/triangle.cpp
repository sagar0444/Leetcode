
class Solution {
public:

    int f(int i, int j, vector<vector<int>>& triangle,
          vector<vector<int>>& dp , vector<vector<bool>>& vis) {

        int n = triangle.size();

        // Base case
        if(i == n-1) {
            return triangle[i][j];
        }

        // Already calculated
        if(vis[i][j]) {
            return dp[i][j];
        }
   vis[i][j] = true;
        int down = triangle[i][j] +
                   f(i+1, j, triangle, dp , vis);

        int diagonal = triangle[i][j] +
                       f(i+1, j+1, triangle, dp , vis);

        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
vector<vector<bool>> vis( n , vector<bool>( n , false));
        return f(0, 0, triangle, dp , vis);
    }
};

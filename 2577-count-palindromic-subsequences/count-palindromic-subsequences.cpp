
class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int i, int c, int f, int s, string& st,
              vector<vector<vector<int>>>& dp) {

        int n = st.size();

        if (c == 5) return 1;
        if (i == n) return 0;

        int key = f * 10 + s;

        if (dp[i][c][key] != -1)
            return dp[i][c][key];

        long long notPick = solve(i + 1, c, f, s, st, dp);

        long long pick = 0;
        int ch = st[i] - '0';

        if (c == 0) {
            pick = solve(i + 1, c + 1, ch, s, st, dp);
        }
        else if (c == 1) {
            pick = solve(i + 1, c + 1, f, ch, st, dp);
        }
        else if (c == 2) {
            pick = solve(i + 1, c + 1, f, s, st, dp);
        }
        else if (c == 3 && ch == s) {
            pick = solve(i + 1, c + 1, f, s, st, dp);
        }
        else if (c == 4 && ch == f) {
            pick = solve(i + 1, c + 1, f, s, st, dp);
        }

        return dp[i][c][key] = (pick + notPick) % MOD;
    }

    int countPalindromes(string st) {
        int n = st.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(5, vector<int>(100, -1))
        );

        return solve(0, 0, 0, 0, st, dp);
    }
};


class Solution {
public:

    int f(vector<int>& days, vector<int>& costs, int index,
          vector<int>& dp) {

        // Base case
        if (index >= days.size()) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        // Option 1: Buy a 1-day pass
        int option1 = costs[0] + f(days, costs, index + 1, dp);

        // Option 2: Buy a 7-day pass
        int i = index;
        while (i < days.size() && days[i] < days[index] + 7) {
            i++;
        }

        int option2 = costs[1] + f(days, costs, i, dp);

        // Option 3: Buy a 30-day pass
        i = index;
        while (i < days.size() && days[i] < days[index] + 30) {
            i++;
        }

        int option3 = costs[2] + f(days, costs, i, dp);

        return dp[index] = min(option1, min(option2, option3));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {

        vector<int> dp(days.size(), -1);

        return f(days, costs, 0, dp);
    }
};


class Solution {
public:

    int f(vector<int>& nums, int index , vector<int>& dp) {

        // Base case
        if (index >= nums.size()) {
            return 0;
        }

        if( dp[index] != -1){
             return dp[index];
        }

        // Pick current house
        int pick = nums[index] + f(nums, index + 2 , dp);

        // Don't pick current house
        int notPick = f(nums, index + 1, dp);

         return dp[index] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        vector<int> first, second;

        for (int i = 0; i < n; i++) {

            // Exclude last house
            if (i != n - 1) {
                first.push_back(nums[i]);
            }

            // Exclude first house
            if (i != 0) {
                second.push_back(nums[i]);
            }
        }

        // int ans1 = f(first, 0);
        // int ans2 = f(second, 0);
  vector<int>dp1(first.size() , -1);
  vector<int>dp2(second.size() , -1);
        return max(f(first,0,dp1), f(second,0,dp2));
    }
};

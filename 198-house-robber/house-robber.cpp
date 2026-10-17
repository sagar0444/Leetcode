class Solution {
public:
    int solveByrecursion( int index , vector<int>& nums){

        if( index >= nums.size()){

            return 0;
    }

    int include = nums[index] + solveByrecursion(index + 2 , nums);
    int exclude = 0 + solveByrecursion(index + 1, nums);

    int ans = max( include , exclude);
    return ans;
    }
int solveMemo( int index ,vector<int>& nums ,  vector<int>& dp){
 if( index >= nums.size()){

            return 0;
    }

    if( dp[index] != -1){
         return dp[index];
    }

    int include = nums[index] + solveMemo(index + 2 , nums , dp);
    int exclude = 0 + solveMemo(index + 1, nums , dp);

    dp[index] = max( include , exclude);
    return dp[index];


}

    int rob(vector<int>& nums) {
        int index = 0;
    int n = nums.size();
        vector<int> dp(n+ 1 , -1);
        int ans = solveMemo( index , nums , dp);
        return ans ;
    }
};
class Solution {
public:
int f( vector<int>& nums , int index , vector<int>& dp){
    // base case
    if( index >= nums.size()){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    int pick = nums[index] + f(nums, index+2 ,dp);
    int notPick = 0 + f(nums,index+1 ,dp);
    return dp[index] = max(pick , notPick);
     return dp[index];
}
    int rob(vector<int>& nums) {
        int index = 0;
         int n = nums.size();
         vector<int>dp(n+1 , -1);
         return f(nums, index,dp);
    }
};
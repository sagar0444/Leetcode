class Solution {
public:
  int solve( int index , int target , vector<int>& nums , vector<vector<int>>& dp){
    if( target == 0) return true;
    if( index == 0) return nums[0] == target;
    if(dp[index][target] != -1){
    return dp[index][target];}
    bool notTake = solve( index - 1 , target , nums ,dp);
     bool take = false ;
      if(nums[index] <= target){
         take = solve( index - 1 , target - nums[index] , nums , dp);
      }
        return dp[index][target] =take || notTake;
  }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
         for( int x : nums){
             sum += x;
         }
         if( sum % 2 != 0) return false;
         int target = sum / 2 ;
         vector<vector<int>> dp(n+1 , vector<int>(target+1 , -1));
         return solve(n-1 , target , nums , dp);
    }
};
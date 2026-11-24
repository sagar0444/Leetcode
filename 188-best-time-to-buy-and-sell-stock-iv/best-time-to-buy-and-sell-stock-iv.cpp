class Solution {
public:
int f(int index , int buy , int k , vector<int>& prices, int n , vector<vector<vector<int>>>&dp){
    // base case
    if( index == n || k == 0){
         return 0;
    }
    if( dp[index][buy][k] != -1){
         return dp[index][buy][k];
    }
    int profit = 0;
    if(buy){
     profit = max( -prices[index] + f( index +1 , 0 , k , prices, n , dp) , 0 + f(index+1 , 1 , k , prices, n , dp));
    }
    else{
        profit = max( prices[index] + f( index +1 , 1 , k-1 , prices , n , dp) , 0 + f( index +1 , 0 , k , prices , n , dp));
    }
   dp[index][buy][k] =profit;
   return dp[index][buy][k];
}
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp( n +1 , vector<vector<int>>(2 , vector<int>(k+1 , -1)));
        return f(0 , 1 , k , prices , n , dp);
    }
};
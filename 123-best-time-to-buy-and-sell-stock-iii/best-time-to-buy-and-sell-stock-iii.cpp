class Solution {
public:
int f(int index , int buy , int cap , vector<int>& prices, int n ,vector<vector<vector<int>>>& dp ){
    if( index == n || cap == 0) return 0;
    if( dp[index][buy][cap] !=-1){
         return  dp[index][buy][cap];
    }
  int profit = 0;
    if( buy){
        profit = max(-prices[index] + f(index+1 , 0 ,cap , prices , n , dp) , 0 + f(index+1 , 1 , cap , prices , n, dp));
    }

    else{
         profit = max(prices[index] + f(index+1 , 1 , cap-1 , prices , n , dp  ) , 0 + f(index+1 , 0, cap , prices , n ,dp));
    }
    dp[index][buy][cap] = profit;
    return  dp[index][buy][cap];
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();


vector<vector<vector<int>>> dp(
    n+1,
    vector<vector<int>>(2, vector<int>(3, -1))
);
       return f( 0 , 1 , 2 , prices , n , dp); 


    }
};
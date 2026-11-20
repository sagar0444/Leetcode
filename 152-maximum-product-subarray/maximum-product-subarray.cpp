class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
    
        int maxi = INT_MIN;
         for( int i = 0 ; i <n ; i++){
            int ans  =1 ;
            for( int j = i; j < n ; j++){
                 ans = ans  * nums[j];
                   maxi = max( maxi , ans);
            }

            //   maxi = max( maxi , ans);
         }
       return maxi;
    }
};
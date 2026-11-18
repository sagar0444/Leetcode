class Solution {
public:
 bool isValid( vector<int>& nums , int n , int k , int maxall){
    int count = 1, sum = 0;
     for( int i = 0 ; i <n ; i++){
         if( nums[i] > maxall){
             return false;
         }
         if (sum + nums[i] <= maxall){ sum = sum + nums[i];}
         else{ 
            count ++;
             sum = nums[i];
         }
     }

     return count > k ? false : true;
 }
    int splitArray(vector<int>& nums, int k) {
        int  sum =0;
        int n = nums.size();
        for(int i =0 ; i < n ; i++){
             sum = sum + nums[i];
        }

        int ans = -1 ;
        int st = 0, end = sum;
        while( st <= end){
             int mid = st + ( end - st) /2;

             if(isValid( nums , n , k , mid)){
                 ans = mid ;
                  end = mid -1 ;
             }
             else {
                 st = mid + 1;
             }
        }
        return ans ;
    }
};
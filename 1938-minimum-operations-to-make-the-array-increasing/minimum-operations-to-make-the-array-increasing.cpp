class Solution {
public:
    int minOperations(vector<int>& nums) {
       
         int newDiff = 0;
          for( int i = 1 ; i <nums.size() ; i++){
             int diff =0;
            if(nums[i] <= nums[i-1]){
                 diff= nums[i-1] - nums[i] + 1;
                  newDiff = newDiff + diff;
                //   return newDiff;
                nums[i] = nums[i-1] +1;
            }

            // else {
            //      return 0;
            // }
          }
          return newDiff;
    }
};
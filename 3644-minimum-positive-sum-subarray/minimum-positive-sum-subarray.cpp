class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int prevSum = INT_MAX;
        for( int i = 0 ; i < n ;i++){
             vector<int> arr;
             int sum = 0;
             for( int j = i ; j < n ; j++){
                arr.push_back(nums[j]);
                  sum += nums[j];
                if( arr.size() >= l && arr.size() <= r && sum < prevSum && sum > 0){
                     prevSum = sum;
                }
             }
        }

        if( prevSum == INT_MAX){
             return -1;
        }

        return prevSum ;
    }
};
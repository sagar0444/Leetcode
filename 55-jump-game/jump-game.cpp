class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxInt = 0;
        for( int i = 0 ; i < n ; i++){
            if ( i > maxInt) return false;
            maxInt = max( maxInt , i + nums[i]);
        }
        return true;
    }
};
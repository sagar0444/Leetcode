
class Solution {
public:

    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        vector<int> leftMax(n), rightMax(n);
        vector<int> leftMin(n), rightMin(n);

        stack<int> st;

        // 1. Previous Greater Element
        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            leftMax[i] = st.empty() ? i + 1 : i - st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();


        // 2. Next Greater or Equal Element
        for(int i = n-1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            rightMax[i] = st.empty() ? n - i : st.top() - i;

            st.push(i);
        }

        while(!st.empty()) st.pop();


        // 3. Previous Smaller Element
        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            leftMin[i] = st.empty() ? i + 1 : i - st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();


        // 4. Next Smaller or Equal Element
        for(int i = n-1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            rightMin[i] = st.empty() ? n - i : st.top() - i;

            st.push(i);
        }


        // 5. Calculate sum of maximums and minimums

        long long sumMax = 0;
        long long sumMin = 0;

        for(int i = 0; i < n; i++) {

            sumMax += 1LL * nums[i] * leftMax[i] * rightMax[i];

            sumMin += 1LL * nums[i] * leftMin[i] * rightMin[i];
        }

        return sumMax - sumMin;
    }
};

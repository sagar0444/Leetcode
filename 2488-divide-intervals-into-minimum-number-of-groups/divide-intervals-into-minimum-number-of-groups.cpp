
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        // Step 1: Sort by starting time
        sort(intervals.begin(), intervals.end());

        // Step 2: Min Heap
        priority_queue<int, vector<int>, greater<int>> pq;

        // Step 3: Process every interval
        for(auto &it : intervals) {

            int start = it[0];
            int end = it[1];

            // Step 4: Check if an existing group is free
            if(!pq.empty() && pq.top() < start) {
                pq.pop();
            }

            // Step 5: Add current ending time
            pq.push(end);
        }

        // Step 6: Number of groups
        return pq.size();
    }
};

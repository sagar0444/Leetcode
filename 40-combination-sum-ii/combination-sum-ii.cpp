
class Solution {
public:

    void f(int index, vector<int>& candidates,
           int target, vector<int>& ds,
           vector<vector<int>>& ans) {

        // Target achieved
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicates at the same level
            if (i > index && candidates[i] == candidates[i-1]) {
                continue;
            }

            // Since array is sorted, stop if too large
            if (candidates[i] > target) {
                break;
            }

            // PICK
            ds.push_back(candidates[i]);

            // Move to next index (no reuse)
            f(i + 1, candidates, target - candidates[i],
              ds, ans);

            // Undo the selection
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {

        vector<vector<int>> ans;
        vector<int> ds;

        sort(candidates.begin(), candidates.end());

        f(0, candidates, target, ds, ans);

        return ans;
    }
};

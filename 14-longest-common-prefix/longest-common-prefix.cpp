class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        // Check each character index of the first string
        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];

            // Compare this character with the same index in all strings
            for (int j = 1; j < strs.size(); j++) {
                // If index exceeds or characters don't match → stop
                if (i >= strs[j].size() || strs[j][i] != ch) {
                    return ans;
                }
            }

            // If all strings matched this character → add to answer
            ans += ch;
        }

        return ans;
    }
};
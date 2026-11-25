class Solution {
public:

    bool allZeros(vector<int>& counter) {
        for (int i : counter) {
            if (i != 0)
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {

        int n = s.length();
        int k = p.length();

        vector<int> ans;

        if (k > n) return ans;

        vector<int> counter(26, 0);

        // Store frequency of p
        for (int i = 0; i < k; i++) {
            counter[p[i] - 'a']++;
        }

        int i = 0, j = 0;

        while (j < n) {

            // Add character to window
            counter[s[j] - 'a']--;

            // Window size becomes k
            if (j - i + 1 == k) {

                // Check anagram
                if (allZeros(counter)) {
                    ans.push_back(i);
                }

                // Remove leftmost character
                counter[s[i] - 'a']++;
                i++;
            }

            j++;
        }

        return ans;
    }
};
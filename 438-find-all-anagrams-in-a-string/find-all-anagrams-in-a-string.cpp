
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        int n = s.size();
        int m = p.size();

        if (m > n) return ans;

        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);

        // Store frequency of characters in p
        for (int i = 0; i < m; i++) {
            freqP[p[i] - 'a']++;
        }

        int i = 0;

        for (int j = 0; j < n; j++) {

            // Add current character
            freqS[s[j] - 'a']++;

            // Maintain window size m
            if (j - i + 1 > m) {

                // Remove character from left
                freqS[s[i] - 'a']--;
                i++;
            }

            // Check if both frequencies match
            if (j - i + 1 == m && freqS == freqP) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

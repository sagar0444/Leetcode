
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        const long long MOD1 = 1000000007;
        const long long MOD2 = 1000000009;
        const long long BASE = 911382323;

        vector<long long> h1(n + 1, 0);
        vector<long long> h2(n + 1, 0);

        vector<long long> p1(n + 1, 1);
        vector<long long> p2(n + 1, 1);

        // Build prefix hashes and powers
        for (int i = 0; i < n; i++) {

            h1[i + 1] = (h1[i] * BASE + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE + nums[i]) % MOD2;

            p1[i + 1] = (p1[i] * BASE) % MOD1;
            p2[i + 1] = (p2[i] * BASE) % MOD2;
        }

        // Check whether a unique subarray of length k exists
        auto check = [&](int k) {

            unordered_map<long long, int> freq;

            for (int i = 0; i + k <= n; i++) {

                long long hash1 =
                    (h1[i + k] - h1[i] * p1[k] % MOD1 + MOD1) % MOD1;

                long long hash2 =
                    (h2[i + k] - h2[i] * p2[k] % MOD2 + MOD2) % MOD2;

                long long key = hash1 * MOD2 + hash2;

                freq[key]++;
            }

            for (auto& it : freq) {
                if (it.second == 1) {
                    return true;
                }
            }

            return false;
        };

        // Binary Search
        int low = 1;
        int high = n;
        int ans = n;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        const long long MOD = 1e9 + 7;
        // dp[i][0] = even subarrays ending at i
        // dp[i][1] = odd subarrays ending at i
        vector<vector<long long>> dp(n, vector<long long>(2, 0));

        // 1. Base Case (i = 0)
        bool first_odd = (arr[0] & 1);
        dp[0][0] = first_odd ? 0 : 1;
        dp[0][1] = first_odd ? 1 : 0;

        long long total = dp[0][1];

        // 2. Fill the table from i = 1 to n - 1
        for (int i = 1; i < n; i++) {
            bool curr_odd = (arr[i] & 1);

            if (curr_odd) {
                // Current element is ODD: parity flips from i - 1
                dp[i][1] = (dp[i - 1][0] + 1) % MOD; // even + odd = odd (+1 for [arr[i]])
                dp[i][0] = dp[i - 1][1];             // odd + odd = even
            } else {
                // Current element is EVEN: parity stays same as i - 1
                dp[i][1] = dp[i - 1][1];             // odd + even = odd
                dp[i][0] = (dp[i - 1][0] + 1) % MOD; // even + even = even (+1 for [arr[i]])
            }

            total = (total + dp[i][1]) % MOD;
        }

        return total;
    }
};

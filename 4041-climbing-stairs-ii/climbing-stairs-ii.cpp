class Solution {
public:
    int solve(int n, vector<int>& costs) {

        if (n == 0) return 0;

        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;
        dp[1] = costs[0] + 1;

        if (n >= 2)
            dp[2] = min(dp[1] + costs[1] + 1,
                        costs[1] + 4);

        if (n >= 3)
            dp[3] = min({
                dp[2] + costs[2] + 1,
                dp[1] + costs[2] + 4,
                costs[2] + 9
            });

        for (int i = 4; i <= n; i++) {
            dp[i] = costs[i-1] + min({
                dp[i-1] + 1,
                dp[i-2] + 4,
                dp[i-3] + 9
            });
        }

        return dp[n];
    }

    int climbStairs(int n, vector<int>& costs) {
        return solve(n, costs);
    }
};
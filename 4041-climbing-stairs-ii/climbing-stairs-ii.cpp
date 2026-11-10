
class Solution {
public:
    int solve(int n, vector<int>& costs) {

        if (n == 0) return 0;

        int p1 = 0;                  // dp[0]
        int p2 = costs[0] + 1;      // dp[1]

        if (n == 1) return p2;

        int p3 = min({
            p2 + costs[1] + 1,
            p1 + costs[1] + 4
        });                         // dp[2]

        if (n == 2) return p3;

        int p4 = min({
            p3 + costs[2] + 1,
            p2 + costs[2] + 4,
            p1 + costs[2] + 9
        });                         // dp[3]

        if (n == 3) return p4;

        for (int i = 4; i <= n; i++) {

            int curr = costs[i-1] + min({
                p4 + 1,
                p3 + 4,
                p2 + 9
            });

            p2 = p3;
            p3 = p4;
            p4 = curr;
        }

        return p4;
    }

    int climbStairs(int n, vector<int>& costs) {
        return solve(n, costs);
    }
};

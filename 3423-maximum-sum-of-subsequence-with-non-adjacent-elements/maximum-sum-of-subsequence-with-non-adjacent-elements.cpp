class Solution {
    struct Node {
        long long dp[2][2]; // dp[left_taken][right_taken]
    };

    vector<Node> tree;
    int n;
    const long long MOD = 1e9 + 7;

    Node merge(const Node& L, const Node& R) {
        Node res;
        for (int l = 0; l < 2; l++) {
            for (int r = 0; r < 2; r++) {
                // Combine L and R without taking adjacent boundary elements (L's right and R's left)
                res.dp[l][r] = max({
                    L.dp[l][0] + R.dp[0][r],
                    L.dp[l][0] + R.dp[1][r],
                    L.dp[l][1] + R.dp[0][r]
                });
            }
        }
        return res;
    }

    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            tree[node].dp[0][0] = 0;
            tree[node].dp[0][1] = -1e18; // Invalid state for single element
            tree[node].dp[1][0] = -1e18; // Invalid state for single element
            tree[node].dp[1][1] = nums[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, nums);
        build(2 * node + 1, mid + 1, end, nums);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node].dp[0][0] = 0;
            tree[node].dp[1][1] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, nums);

        long long ans = 0;
        for (const auto& q : queries) {
            update(1, 0, n - 1, q[0], q[1]);
            long long best = max({
                tree[1].dp[0][0],
                tree[1].dp[0][1],
                tree[1].dp[1][0],
                tree[1].dp[1][1]
            });
            ans = (ans + max(0LL, best)) % MOD;
        }
        return ans;
    }
};

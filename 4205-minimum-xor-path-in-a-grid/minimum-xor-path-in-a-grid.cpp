class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // 2048 is a safe upper bound since grid values are <= 1023
        const int MAX_XOR = 2048; 
        
        // dp[r][c][v] = true means value 'v' is a reachable XOR sum at cell (r, c)
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(MAX_XOR, false)));
        
        // Initialize start cell
        dp[0][0][grid[0][0]] = true;
        
        // Process the grid in a clean topological order (row by row, col by col)
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                for (int val = 0; val < MAX_XOR; ++val) {
                    if (!dp[r][c][val]) continue; // State not reachable, skip
                    
                    // Move Down
                    if (r + 1 < m) {
                        dp[r + 1][c][val ^ grid[r + 1][c]] = true;
                    }
                    // Move Right
                    if (c + 1 < n) {
                        dp[r][c + 1][val ^ grid[r][c + 1]] = true;
                    }
                }
            }
        }
        
        // Find the smallest reachable XOR sum at the destination (m-1, n-1)
        for (int i = 0; i < MAX_XOR; ++i) {
            if (dp[m - 1][n - 1][i]) return i;
        }
        
        return -1; 
    }
};

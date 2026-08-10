class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int dr[4] = {-1,  0, 1, 0};
        int dc[4] = { 0,  1, 0, -1};
        for(int r=0;r<row;r++){
        
            for(int c=0;c<col;c++){
                bool ans=1;
                for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nc>=0 && nr<row && nc<col){
                    if(mat[r][c]<mat[nr][nc]){
                        ans=0;
                    }
                }
                }
                if(ans) return {r,c};
            }
        }
        return {0,0};

    }
};
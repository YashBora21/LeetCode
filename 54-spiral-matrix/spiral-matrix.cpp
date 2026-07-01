class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dr[4]={0,1,0,-1};
        int dc[4]={1,0,-1,0};
        int dir=0;
        vector<int>ans;
        vector<vector<bool>> visited(matrix.size(),vector<bool>(matrix[0].size(),false));

        int m=matrix.size();
        int n=matrix[0].size();
        int row=0;
        int col=0;
        for(int i=0;i<m*n;i++){
            ans.push_back(matrix[row][col]);
            visited[row][col]=true;
            int nr=row+dr[dir];
            int nc=col+dc[dir];
            if(nr<0||nc<0||nr>=m||nc>=n||visited[nr][nc]){
                dir=(dir+1)%4;
                nr=row+dr[dir];
                nc=col+dc[dir];
            }
            row=nr;
            col=nc;
        }
        return ans;
    }
};
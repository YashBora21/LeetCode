class Solution {
public:
    void multibfs(vector<vector<int>>& grid,vector<vector<int>>& matrix){
        queue<pair<int,int>>q;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    matrix[i][j]=0;
                }
            }
        }
        
        while(!q.empty()){
            int dr[4]={-1,1,0,0};
            int dc[4]={0,0,-1,1};
            auto ele=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=ele.first+dr[i];
                int nc=ele.second+dc[i];
                if(nr>=0 && nc>=0 && nr<rows && nc<cols && matrix[nr][nc]==-1){
                   
                    matrix[nr][nc]=matrix[ele.first][ele.second]+1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int dijibfs(vector<vector<int>>& grid,vector<vector<int>>& matrix){
        priority_queue<vector<int>>pq;
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>>best(rows,vector<int>(cols,0));
        
        pq.push({matrix[0][0],0,0});
        best[0][0]=matrix[0][0];
        while(!pq.empty()){
            int dr[4]={-1,1,0,0};
            int dc[4]={0,0,-1,1};
            auto ele=pq.top();
            pq.pop();
            
            for(int i=0;i<4;i++){
                int r=ele[1];
                int c=ele[2];
                int s=ele[0];
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>=0 && nc>=0 && nr<rows && nc<cols){
                   int newsafe=min(s,matrix[nr][nc]);
                   if(newsafe>best[nr][nc]){
                    best[nr][nc]=newsafe;
                    pq.push({newsafe,nr,nc});
                   }
                    
                }
            }

        }
        return best[rows-1][cols-1];
        
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>>matrix(rows,vector<int>(cols,-1));
        multibfs(grid,matrix);
        return dijibfs(grid,matrix);

    }
};
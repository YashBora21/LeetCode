class Solution {
public:
    int bfs(vector<vector<int>>& grid,int &fresh){
        queue<pair<int,int>>q;
        int time=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        int rows=grid.size();
        int cols=grid[0].size();

        while(!q.empty()){
            
            int size=q.size();
            
            bool change=false;
            
            for(int i=0;i<size;i++){
                auto rotten=q.front();
                q.pop();
                for(int j=0;j<4;j++){
                int nr=rotten.first+dr[j];
                int nc=rotten.second+dc[j];
                if(nr>=0&&nc>=0&&nr<rows&&nc<cols&&grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    fresh--;
                    q.push({nr,nc});
                    change=true;
                }
                }
            }
            if(change)time++;

        }
        if(fresh>0) return -1;
        
        return time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0; 
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1) fresh++;
            }
        }
        
        
        return bfs(grid,fresh);
    }
};
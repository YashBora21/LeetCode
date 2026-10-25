class Solution {
public:
    void bfs(vector<vector<int>> & grid,int r,int c){
        int dir[4][2]={
            {-1,0},{1,0},{0,-1},{0,1}
        };
        queue<pair<int,int>>q;
        q.push({r,c});
        grid[r][c]=1;
        while(!q.empty()){
            auto [rc,cc]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=rc+dir[i][0];
                int nc=cc+dir[i][1];
                if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==0 ){
                     grid[nr][nc]=1;
                     q.push({nr,nc});
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(r==0 ||r==grid.size()-1 || c==grid[0].size()-1 || c==0){
                   if(grid[r][c]==0)  bfs(grid,r,c);
                }
            }


        }
        int ans=0;
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
              if(grid[r][c]==0)  {ans++;
                bfs(grid,r,c);}
            }
            
        }
        return ans;
    }
};
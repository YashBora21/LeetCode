class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        int ans=0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]>0){
                    queue<pair<int,int>>q;
                long long island_sum=0;
                    q.push({r,c});
                    island_sum+=grid[r][c];
                    grid[r][c]=0;
                    while(!q.empty()){
                        auto[a,b]=q.front();q.pop();
                        for(int i=0;i<4;i++){
                            int nr=dir[i][0]+a;
                            int nc=dir[i][1]+b;
                            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]>0){
                                    island_sum+=grid[nr][nc];
                                    grid[nr][nc]=0;
                                    q.push({nr,nc});
                            }
                        }
                    }
                    if(island_sum%k==0)ans++;
                    
                }
            }
        }
        return ans;
    }
};
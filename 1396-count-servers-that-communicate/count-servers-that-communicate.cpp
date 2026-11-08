class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
     int ans=0;
     vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
     for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j] && !visited[i][j]){
                queue<pair<int,int>>q;
                q.push({i,j});
                visited[i][j]=true;
               
                int count=0;

                while(!q.empty()){
                auto [r,c]=q.front();
                q.pop();
                count++;
                for(int k=0;k<grid[0].size();k++){
                    if(grid[r][k] && !visited[r][k]){
                        q.push({r,k});
                         visited[r][k]=true;
                    }
                }
                for(int k=0;k<grid.size();k++){
                    if(grid[k][c] && !visited[k][c]){
                        q.push({k,c});
                         visited[k][c]=true;
                    }
                }

            }
            if(count>1) ans+=count;
            }
            
        }
     }   
     return ans;
    }
};
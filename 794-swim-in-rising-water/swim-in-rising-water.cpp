class Solution {
public:
    int dijibfs(vector<vector<int>>& grid,vector<vector<int>>& distance){
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int rows=grid.size();
        int cols=grid[0].size();
        
        pq.push({grid[0][0],0,0});
        distance[0][0]=grid[0][0];
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
                   int newcost=max(s,grid[nr][nc]);
                   if(newcost<distance[nr][nc]){
                    distance[nr][nc]=newcost;
                    pq.push({newcost,nr,nc});
                   }
                    
                }
            }

        }
        return distance[rows-1][cols-1];
        
    }

    int swimInWater(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>>distance(rows,vector<int>(cols,INT_MAX));
        return dijibfs(grid,distance);
    }
};
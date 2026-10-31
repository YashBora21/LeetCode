class Solution {
public:
   const long long  MOD=1e9 + 7;
    pair<int,int> path(int i,int j,int dir,int m,int n,vector<vector<int>>& grid){
        if(dir==0){
                j++;
            }
            else i++;
        while( i>=0 && i<m && j>=0 && j<n  && grid[i][j]){
            if(dir==0){
                dir=1;
                i++;
            }
            else {dir=0;
                j++;}
        }
        if(i < 0 || i >= m || j < 0 || j >= n)
            return {-1, -1}; 
        return {i,j};
    }
    int uniquePaths(vector<vector<int>>& grid) {
        long long m=grid.size();
        long long n=grid[0].size();
        vector<vector<long long>> ways(m, vector<long long>(n, 0));
        ways[0][0]=1;
        int dir[2][2]={
            {0,1},{1,0}
        };
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ways[i][j]==0)continue;
                    for(int d=0;d<2;d++){
                        auto[x,y]=path(i,j,d,m,n,grid);
                        if(x==-1) continue;
                        ways[x][y] = (ways[x][y] + ways[i][j]) % MOD;
                    }
                } 
            
        }
        return ways[m-1][n-1];
    }
};
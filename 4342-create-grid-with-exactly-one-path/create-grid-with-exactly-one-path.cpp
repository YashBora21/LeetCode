class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<int>>matrix(m,vector<int>(n,0));
        for(int c=0;c<n;c++){
            matrix[0][c]=1;

        }
        for(int r=1;r<m;r++){
            matrix[r][n-1]=1;
        }
        vector<string> ans;
        for(int i=0;i<m;i++){
            string s="";
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    s+='.';
                }
                else{
                    s+='#';
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};
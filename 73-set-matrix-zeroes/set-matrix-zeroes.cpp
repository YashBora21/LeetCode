class Solution {
public:
    void build(vector<vector<int>>& matrix,int row,int col){
        for(int i=0;i<matrix[row].size();i++){
            matrix[row][i]=0;
        }
        for(int i=0;i<matrix.size();i++){
            matrix[i][col]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>>mark(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    mark[i][j]=0;
                
                }
            }
        }
          for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(mark[i][j]==0){
                    build(matrix,i,j);
                
                }
            }
        }
    }
};
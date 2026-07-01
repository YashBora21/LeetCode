class Solution {
public:
    bool isequal(vector<vector<int>>& mat, vector<vector<int>>& target){
        for(int i=0;i<mat.size();i++){
            for(int j=i+1;j<mat[i].size();j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<mat[0].size();i++){
            reverse(mat[i].begin(),mat[i].end());
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
               if(mat[i][j]!=target[i][j])return false;
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat.size()!=target.size())return false;
        //90 180 270 360  90s  incremental
        for(int i=0;i<4;i++){
            if(isequal(mat,target)) return true;
        }
        return false;
        
       
    }
};
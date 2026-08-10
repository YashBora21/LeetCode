class Solution {
public:
    int findmaxrowincol(vector<vector<int>>& mat,int col){
        int max_row=0;
        int max_ele=INT_MIN;
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]>max_ele){
                max_row=i;
                max_ele=mat[i][col];

            }
        }
        return max_row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int low=0;
        int high=col-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int max_row=findmaxrowincol(mat,mid);
            int left=-1;
            int right=-1;
            if(mid-1>=0){
                left=mat[max_row][mid-1];
            }
             if(mid+1<col){
                right=mat[max_row][mid+1];
            }
            if(mat[max_row][mid]>left && mat[max_row][mid]>right ){
                return {max_row,mid};
            }
            else if(mat[max_row][mid]<left){
                high=mid-1;

            }
            else{
                low=mid+1;
            }
        }
        return{0,0};
       

    }
};
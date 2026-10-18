class Solution {
public:
long long MOD = 1e9 + 7;
    int bst(vector<int>&nums,vector<vector<long long>>&comb){
        if(nums.size()<=1) return 1;
        int node =nums[0];
        vector<int>left;
        vector<int>right;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<node)left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        long long currcom=comb[left.size()+right.size()][left.size()];
            long long leftways=bst(left,comb);
            long long rightways=bst(right,comb);

            return ((((currcom*leftways)%MOD)*rightways)%MOD);
    }
    int numOfWays(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<vector<long long>>comb(nums.size() + 1, vector<long long>(nums.size() + 1, 0));
        for(int i=0;i<nums.size();i++){
            //nc0 is alway 1
            comb[i][0]=1;
            for(int j=1;j<=i;j++){
                comb[i][j]=(comb[i-1][j-1] + comb[i-1][j])%MOD;

            }
           
        }
         return bst(nums,comb)-1;
    }
};
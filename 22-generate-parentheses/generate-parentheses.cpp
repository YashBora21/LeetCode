class Solution {
public:
    void gen(int n,vector<string> &ans,int open,int close,string curr){
        if(close==n && open==n){
            ans.push_back(curr);
            return ;
        }
        if(open<n){
            gen(n,ans,open+1,close,curr+'(');
        }
         if(close<open){
            gen(n,ans,open,close+1,curr+')');
        }

    
        
         
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen(n,ans,0,0,"");
        return ans;
    }
};
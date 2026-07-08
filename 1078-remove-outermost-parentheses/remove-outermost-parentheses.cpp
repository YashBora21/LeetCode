class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth=0;
        string ans="";
        for(auto c:s){
            if(depth>0 && c=='('){
                ans+=c;
            }
            if(c=='(')depth++;
            else depth--;
           if(depth>0 && c==')'){
            
            ans+=c;
           }

        }
        return ans;
    }
};
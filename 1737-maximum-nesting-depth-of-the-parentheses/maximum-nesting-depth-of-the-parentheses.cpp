class Solution {
public:
    int maxDepth(string s) {
        int maxdep=INT_MIN;
        int depth=0;
        
        for(auto i:s){
            if(i=='('){
                depth++;
            }
            else if(i==')') {
                maxdep=max(maxdep,depth);
                depth--;
            }
        }
        if(maxdep==INT_MIN) return 0;
        return maxdep;
    }
};
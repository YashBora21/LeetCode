class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int child_ptr=0;
        int cokkie=0;
        while(child_ptr < g.size() && cokkie<s.size()){
            if(g[child_ptr] <= s[cokkie]){
                child_ptr++;
            }
            cokkie++;
        }
        return child_ptr;
    }
};
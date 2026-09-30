class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ans;
        stack<int> st;
        int depth=0;
        for(auto ch : seq){
            if(ch=='('){
                    ans.push_back(depth%2);
                    depth++;
            }
            else{
                depth--;
                ans.push_back(depth%2);
                    
            }
        }
        return ans;
    }
};
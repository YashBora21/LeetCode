class Solution {
public:
    bool isvalid(string s){
        int balance=0;
        for(auto ch:s){
            if(ch=='(') balance++;
            else if(ch==')') balance--;
            if(balance<0) return false;
        }
        return balance==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        q.push(s);
        vector<string>ans;
        unordered_set<string>visited; 
        while(!q.empty()){
           int size=q.size();
           vector<string> level;
            for(int i=0;i<size;i++){
                string curr=q.front();
                q.pop();
                level.push_back(curr);
                if(isvalid(curr)){
                    ans.push_back(curr);
                }
            }
            if(!ans.empty()) return ans;
            for(auto curr:level){
                for(int i=0;i<curr.size();i++){
                    if(s[i]!=')' && s[i]!='('){
                        continue;
                    }
                string next = curr.substr(0, i) + curr.substr(i + 1);
                if(visited.insert(next).second){
                    q.push(next);
                }
                }
            }
        }
        return ans;
    }
};
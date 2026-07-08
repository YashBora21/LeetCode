class Solution {
public:
   
    string reverseWords(string s) {
        stringstream ss(s);
        string token;
        vector<string> ans;
        
        while(ss>>token){
            if(ans.size()!=0){
                ans.push_back(" ");
                }
            ans.push_back(token);
        }
        reverse(ans.begin(),ans.end());
        string res="";
        for(auto s:ans){
            res+=s;
        }
        return res;
    }
};
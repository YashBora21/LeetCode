class Solution {
public:
    string reverseParentheses(string s) {
        string ans="";
        bool counter=0;
        stack<char>st;
        for(auto ch : s){
            if(ch==')'){
                string temp="";
                
                while(!st.empty() && st.top()!='('){
                    temp+=st.top();st.pop();
                }
                if(!st.empty())st.pop();//for open braces
                for(auto c:temp){
                    st.push(c);
                }
            }
            else{
                st.push(ch);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    int longestValidParentheses(string s) {
      int left=0,right=0,len=0;

        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                right++;
            }
            else{
                left++;
            }
            if(right==left){
                len=max(len,right+left);
            }
            else if(right>left) {
                right=0;left=0;
            }
        }
        right=0,left=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='('){
                left++;
            }
            else{
                right++;
            }
            if(right==left){
                len=max(len,right+left);
            }
            else if(right<left) {
                right=0;left=0;
            }
        }
        return len;
    }
};
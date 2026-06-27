class Solution {
public:
    bool isPalindrome(string s) {
        string s1="";
       for(char ch:s){
        if(isalnum(ch)){
            s1+=tolower(ch);
        }
       }
       string s2=s1;
       reverse(s1.begin(),s1.end());
       return s1==s2;

    }
};
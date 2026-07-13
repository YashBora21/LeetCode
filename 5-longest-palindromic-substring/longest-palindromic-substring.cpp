class Solution {
public:
    string longestPalindrome(string s) {
        int max_len=1;
        int start=0;
        //odd len pallindrone
        for(int i=0;i<s.length();i++){
            int left=i,right=i;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                if(max_len<(right-left)+1){
                    max_len=(right-left)+1;
                    start=left;
                }
                left--;
                right++;
            }
        }
        
        //even len pallidrone 
           for(int i=0;i<s.length();i++){
            int left=i,right=i+1;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                if(max_len<(right-left)+1){
                    max_len=(right-left)+1;
                    start=left;
                }
                left--;
                right++;
            }
          
        }
        return s.substr(start,max_len);
        
        
    }
};
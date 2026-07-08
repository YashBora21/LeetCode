class Solution {
public:
    string largestOddNumber(string num) {
        int right=-1;
        for(int i=num.length()-1;i>=0;i--){
            if((num[i]-'0')&1){ right= i;break;}
        }
        if(right==-1) return "";
        return num.substr(0,right+1); 
    }
};
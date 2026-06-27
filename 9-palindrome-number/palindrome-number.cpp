class Solution {
public:
    bool isPalindrome(int x) {
       long long num=0;
        //if(x<=-(2**31) ||x>(2**31-1))return 0;
        int temp=x;
        if(temp<0) return false;
       while(x!=0){
            int digit=x%10;
            num=num*10+digit;
            x/=10;
        }
        if (num==temp)  return true;
         return false;
    }
};
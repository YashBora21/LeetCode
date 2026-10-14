class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        int cur=9;
        if (sum < 0 || sum >(long long)9*num)
            return "";
        while(ans.size()!=num){
            if(sum>=cur && cur>=0){
                ans+=cur+'0';
                sum-=cur;
                cur=9;
            }
            else{
                cur--;
            }
        }
        return ans;

    }
};
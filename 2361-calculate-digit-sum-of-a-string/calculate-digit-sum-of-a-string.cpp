class Solution {
public:
    string solve(string s,int k){
        string ans="";
        int sum=0;
        int j=k;
        for(auto i:s){
             if(k==0){
                ans+=to_string(sum);
                k=j;
                sum=0;

            }
            sum+=i-'0';
            k--;
           
        }
        ans+=to_string(sum);
        return ans;
    }
    string digitSum(string s, int k) {
        
        while(s.length()>k){
            s=solve(s,k);
        }
        
        return s;
    }
};
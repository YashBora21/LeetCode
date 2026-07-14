class Solution {
public:
vector<int> ans;
    void solve(int num,int low,int high){
        if(num>high) return ;
        if(num>=low) ans.push_back(num);
        int lastdigit=num%10;
        if(lastdigit==9) return ;
        else{
            solve((num*10)+(lastdigit+1),low ,high);
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        for(int i=1;i<=9;i++){
            solve(i,low,high);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
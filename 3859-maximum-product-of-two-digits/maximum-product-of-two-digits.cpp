class Solution {
public:
    int maxProduct(int n) {
        vector<int>digit;
        while(n!=0){
            digit.push_back(n%10);
            n/=10;

        }
        int max1=INT_MIN;
        int max2=INT_MIN;
        for(auto i:digit){
            if(i>max1){
                max2=max1;
                max1=i;
            }
            else if(i>max2){
                max2=i;
            }
        }
        return max1*max2;

    }
};
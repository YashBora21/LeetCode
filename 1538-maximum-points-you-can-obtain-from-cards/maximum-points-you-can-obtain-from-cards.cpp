class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total=0;
        int ele=0;
        for(int i=cardPoints.size()-k;i<cardPoints.size();i++){
            
           total +=cardPoints[i];
        }
        ele=total;
        for(int right=0;right<k;right++){

            ele-=cardPoints[cardPoints.size()-k+right];
            ele+=cardPoints[right];
            total=max(ele,total);
        }
        return total;
    }
};
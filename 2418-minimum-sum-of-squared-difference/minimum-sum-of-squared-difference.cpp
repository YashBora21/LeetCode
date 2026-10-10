class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
     vector<int> diff;
     for(int i=0;i<nums1.size();i++){
        diff.push_back(abs(nums1[i]-nums2[i]));
     }  
     
     int low=0;
     int high=*max_element(diff.begin(),diff.end());
    
    long long k=k1+k2;
    while(low<high){
        int h=low+(high-low)/2;
        long long needed=0;
        for(auto d:diff){
            if(d>h){
                needed+=d-h;
            }
        }
        if(needed<=k){
            high=h;
        }
        else{
            low=h+1;
        }

    }
    int h=low;
    for(auto &d:diff){
        if(d>h){
            k-=d-h;
            d=h;
        }

    }
    long long ans=0;
    for(auto d:diff){
        if(d==h && k>0 && d>0){
            k--;
            d--;
        } 
        ans+=1LL*d*d;
    }
    return ans;
    }
};
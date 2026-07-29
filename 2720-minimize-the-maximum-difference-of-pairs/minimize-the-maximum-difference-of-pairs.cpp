class Solution {
public:
bool canmake(vector<int>& nums,int mid ,int k){
        int pair=0;
        for(int i=1;i<nums.size();i++){
            if((nums[i]-nums[i-1])<=mid){
                pair++;
                i++;
            }
            
            if(pair>=k){
                return true;
            }
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if(nums.size()<=1) return 0; 
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums.back()-nums.front();
        while(high>=low){
            int mid=low+((high-low)>>1);
            if(canmake(nums,mid,p)){
                high=mid-1;

            }
            else{
                low=mid+1;
            }

        }
        return low;
    }
};


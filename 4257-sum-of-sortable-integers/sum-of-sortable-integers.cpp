class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size(),ans=0;
        cout<<n;
        vector<int> div,drops(n,0);
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                div.push_back(i);
                if(n/i!=i) div.push_back(n/i);
            }
        }
        sort(div.begin(),div.end());
        for(int i=1;i<n;i++) if(nums[i]<nums[i-1]) drops[i]++;
        for(int i=1;i<n;i++) drops[i]+=drops[i-1];
        if(drops[n-1]==0){
            for(auto x : div) ans+=x;
            return ans;
        }
        for(auto len : div){   
            if(len==1) continue; 
            int mini=INT_MAX,maxi=INT_MIN,flag=0;
            for(int i=0;i<n;i+=len){
                int s=i,e=i+len-1,mid;
                int num_of_drops=drops[e]-((s-1>=0)?drops[s-1]:0);
                if(num_of_drops>1){
                    flag=1;
                    break;
                }
                else if(num_of_drops==1){
                    // 1) check whether it is a rotated sorted array drop by comparing start and end
                    if(nums[s]<nums[e]){
                        flag=1;
                        break;
                    }
                    while(s<=e){
                        mid=s+(e-s)/2;
                        if(nums[mid]>nums[e]) s=mid+1;
                        else if(nums[mid]<nums[e]) e=mid;
                        else{
                            if(nums[e-1]>nums[e]){
                                s=e;
                                break;
                            }
                            e--;
                        } 
                    }
                    // pivot/drop index will be s
                }
                // 2) check whether the mini & maxi are right by comparing with existing ones
                if(i==0){
                    mini=nums[s];
                    maxi=(s==0)?nums[e]:nums[s-1];
                }
                else{
                    int cur_mini=nums[s];
                    int cur_maxi=(s==i)?nums[e]:nums[s-1];
                    if(maxi>cur_mini){
                        flag=1;
                        break;
                    }
                    maxi=cur_maxi;
                }
            }
            if(flag==0) ans+=len;
        }
        return ans;
    }
};
class NumArray {
public:
    vector<int>arr;
    vector<int>data;
    void buildtree(int root,int left,int right){
        if(left==right){
            arr[root]=data[right];
            return;
        }
        int mid=left+(right-left)/2;
        buildtree(2*root+1,left,mid);
        buildtree(2*root+2,mid+1,right);
        arr[root]=arr[2*root+1]+arr[2*root+2];
    }
    int query(int start,int end,int node,int left,int right){
                int mid=left+(right-left)/2;
        if( right<start || left>end) return 0;
        if (left >= start && right <= end) return arr[node];
        return (query(start,end,2*node+1,left,mid)+query(start,end,2*node+2,mid+1,right));

    }
    NumArray(vector<int>& nums) {
        if(nums.size()==0) return ;
        data=nums;
        arr.resize(4*nums.size(),0);
        buildtree(0,0,nums.size()-1);

    }
    
    int sumRange(int left, int right) {
        return query(left,right,0,0,data.size()-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
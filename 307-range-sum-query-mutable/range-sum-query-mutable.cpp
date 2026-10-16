class NumArray {
public:
    vector<int> tree;
    vector<int> data;
    void buildtree(int node,int left,int right){
        if(left==right){
            tree[node]=data[right];
             return ;}
        int mid=left+(right-left)/2;
        buildtree(2*node+1,left,mid);
        buildtree(2*node+2,mid+1,right);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    int query(int start,int end,int node,int left,int right){
        if(left>end || right<start) return 0;
        int mid=left+(right-left)/2;
        if(start<=left && end>=right) return tree[node];
        return (query(start,end,2*node+1,left,mid)+query(start,end,2*node+2,mid+1,right));
    }
    void change(int idx,int val,int node,int left,int right){
        if(left==right) {
            tree[node]=val;
            data[idx]=val;
            return ;
        }
        int mid=left+(right-left)/2;
        if(idx<=mid){
            change(idx,val,2*node+1,left,mid);
        }
        else{
            change(idx,val,2*node+2,mid+1,right);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; 
    }
    NumArray(vector<int>& nums) {
        if(nums.size()==0) return ;
        data=nums;
        tree.resize(4*nums.size(),0);
        buildtree(0,0,data.size()-1);

    }
    
    void update(int index, int val) {
        change(index,val,0,0,data.size()-1);
    }
    
    int sumRange(int left, int right) {
        return query(left,right,0,0,data.size()-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
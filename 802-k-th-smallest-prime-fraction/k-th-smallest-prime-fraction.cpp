
class Solution {
public:
    struct FractionCompare {
    vector<int>& arr;

    // Constructor to capture the array reference
    FractionCompare(vector<int>& external_arr) : arr(external_arr) {}

    // Explicitly using std::pair<int, int> instead of a typedef
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        // Cross-multiplication prevents floating-point division errors
        // Max-Heap: returns true if fraction 'a' < fraction 'b'
        return (arr[a.first] * arr[b.second]) > (arr[b.first] * arr[a.second]);
    }
};
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    FractionCompare comp(arr);
    priority_queue<pair<int,int>,
                vector<pair<int,int>>,
                FractionCompare> pq(comp);      
       for(int j=1;j<arr.size();j++){
        
            pq.push({0,j});
       }
       while(--k){
        auto i=pq.top();
        pq.pop();
        if(i.first+1<i.second){
            pq.push({i.first+1,i.second});
        }
       }
       auto i=pq.top();
       vector<int>ans;
       ans.push_back(arr[i.first]);
       ans.push_back(arr[i.second]);
       return ans;
        
    }
};
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>pq;
        long long  total=0;
        for(auto i:target){
            pq.push(i);
            total+=i;
        }
        while(!pq.empty()){
            int maxele=pq.top();
            pq.pop();
            if(maxele==1)return true;
            long long others = total - maxele;
            if (others == 1)
                return true;

            if (others == 0 || maxele <= others)
                return false;
            
            long long previous = maxele % others;
            if (previous == 0)
    return false;

            pq.push(previous);

            total=others+previous;
        }
        return false;
    }
};
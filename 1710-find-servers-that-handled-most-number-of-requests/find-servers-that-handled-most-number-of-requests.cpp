class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> server;
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;        
        for(int i=0;i<k;i++){
            server.insert(i);
        }
        vector<int>count(k,0);
        for(int i=0;i<arrival.size();i++){
            //remove the   doned server
            while(!pq.empty() && pq.top().first<=arrival[i]){
                server.insert(pq.top().second);
                pq.pop();
            }
            if(server.empty()) continue;
            int end=arrival[i]+load[i];
            //find the closet server available for current request
            int prefered=i%k;
            auto it=server.lower_bound(prefered);
            if(it==server.end()){
                it=server.begin();

            }
            int id=*it;
            server.erase(it);
            pq.push({end,id});
            count[id]++;
        
        }
        int maxi=*max_element(count.begin(),count.end());
        vector<int>ans;
        for(int i=0;i<count.size();i++){
             if(count[i] == maxi) {
                ans.push_back(i);
            }
        }
        return ans;


    }
};
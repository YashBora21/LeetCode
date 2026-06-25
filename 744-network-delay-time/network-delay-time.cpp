class Solution {
public:
    void dijibfs(unordered_map<int,vector<pair<int,int>>>&adj,set<pair<int,int>>&st,vector<int>&dist,int n,int k){
        st.insert({0,k});
        dist[k]=0;
        while(!st.empty()){
            auto top=*st.begin();
            st.erase(st.begin());
            for(auto i:adj[top.second]){
                int distance=top.first+i.first;
                if(dist[i.second]>distance){
                    dist[i.second]=distance;
                    st.insert({distance,i.second});
                }
            }
        }
    }
    void build(vector<vector<int>>& times,unordered_map<int,vector<pair<int,int>>>&adj){
        for(auto i:times){
            int u=i[0];
            int v=i[1];
            int dis=i[2];
            adj[u].push_back({dis,v});
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        build(times,adj);
        vector<int>dist(n+1,INT_MAX);
        set<pair<int,int>>st;
        dijibfs(adj,st,dist,n,k);\
        int maxi=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            maxi=max(maxi,dist[i]);
        }
        return maxi;
    }
};
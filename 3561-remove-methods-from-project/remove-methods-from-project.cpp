class Solution {
public:
    void dfs(unordered_map<int,list<int>>&adj,unordered_map<int,bool>& visited,int node){
        
        visited[node]=true;
        
       
        for(auto i:adj[node]){
            if(!visited[i]){
                dfs(adj,visited,i);
            }
            
            
        }
    }
    void build(unordered_map<int,list<int>>&adj, vector<vector<int>>& invocations){
        for(auto i:invocations){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,list<int>> adj;
        unordered_map<int,bool>visited;
        build(adj,invocations);
                dfs(adj,visited,k);
                vector<int> count;
                    bool canRemove = true;

                  for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!visited[u] && visited[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Return remaining (non-suspicious) methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                ans.push_back(i);
        }

        return ans;    
        }
    
};
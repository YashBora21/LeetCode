class Solution {
public:
        bool dfs(unordered_map<int,list<int>>&adj,vector<int>&color,int node,int curr_color){
        color[node]=curr_color;
        
        for(auto i:adj[node]){
            if(color[i]==-1){
                if(!dfs(adj,color,i,1-curr_color)){
                    return false;
                }
                
            }
            else if(color[i]==curr_color){
                    return false;
                }
        }
        return true;
        
    }
    void build(vector<vector<int>>& dislikes,unordered_map<int,list<int>>&adj){
        for(int i=0;i<dislikes.size();i++){
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if(dislikes.size()==0) return true;
        unordered_map<int,list<int>>adj;
        build(dislikes,adj);
        vector<int>color(n+1,-1);
        for(int i=1;i<n+1;i++){

            if(color[i]==-1){

                if(!dfs(adj,color,i,0))
                    return false;
            }
        }

        return true;
    }
};
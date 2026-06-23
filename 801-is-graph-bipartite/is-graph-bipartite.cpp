class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>&color,int node,int curr_color){
        color[node]=curr_color;
        
        for(auto i:graph[node]){
            if(color[i]==-1){
                if(!dfs(graph,color,i,1-curr_color)){
                    return false;
                }
                
            }
            else if(color[i]==curr_color){
                    return false;
                }
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size()==0) return true;
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){

            if(color[i]==-1){

                if(!dfs(graph,color,i,0))
                    return false;
            }
        }

        return true;
        
        

    }
};
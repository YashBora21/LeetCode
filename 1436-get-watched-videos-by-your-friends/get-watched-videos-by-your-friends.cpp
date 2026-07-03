class Solution {
public:
    vector<int>bfs(vector<vector<int>>& friends, int id, int level){
        queue<int>q;
        vector<bool>visited(friends.size(),false);
        q.push(id);
        visited[id]=true;
        int curr_level=0;
        vector<int>pepole;
        while(!q.empty()){
            int size=q.size();
            
            if(curr_level==level) { 
                while(!q.empty())
                {
                    pepole.push_back(q.front());q.pop();
                    }
                    break;
                }
            for(int i=0;i<size;i++){

                int top=q.front();
                
                q.pop();
                for(auto k:friends[top])
                if(!visited[k]){
                    q.push(k);
                    visited[k]=true;
                }
                
            }
            curr_level++;
            
        }
        return pepole;
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<int>ans=bfs(friends,id,level);
        unordered_map<string,int>m;
        for(int i=0;i<ans.size();i++){
            for(auto j : watchedVideos[ans[i]]){
                m[j]++;
            }
        }
        vector<pair<string,int>> mp(m.begin(),m.end());
        vector<string>res;
        sort(mp.begin(),mp.end(),[](const auto&a,const auto& b){
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        for(auto i:mp){
            res.push_back(i.first);
        }
        return res;
        
    }
};
class Solution {
public:
    int dijibfs(
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>& pq,
        vector<vector<int>>&efforts,
        vector<vector<int>>& heights
    ){
        pq.push({0,{0,0}});
        efforts[0][0]=0;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();
            int curr_eff=front.first;
            for(int i=0;i<4;i++){
                int row=front.second[0];
                int col=front.second[1];
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0&&nc>=0&&nr<heights.size()&&nc<heights[0].size()){
                    int diff=abs(heights[row][col]-heights[nr][nc]);
                    int new_eff=max(curr_eff,diff);

                    if(efforts[nr][nc]>new_eff) 
                   { efforts[nr][nc]=new_eff;
                    pq.push({new_eff,{nr,nc}});
                    }
                }
            }
            
            
        }
        return efforts[heights.size()-1][heights[0].size()-1];
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;
        vector<vector<int>>efforts(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        return dijibfs(pq,efforts,heights);
    }
};
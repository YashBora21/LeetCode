/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      queue<TreeNode*> q;
      vector<vector<int>>ans;
      if(root)q.push(root);
       bool counter=0;
      while(!q.empty()){
        int size=q.size();
        vector<int>row;
       
        for(int i=0;i<size;i++){
            TreeNode * temp=q.front();
            q.pop();
            row.push_back(temp->val);
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        if(counter){
            counter=0;
            reverse(row.begin(),row.end());
            ans.push_back(row);
        }
        else{
            counter=1;
            ans.push_back(row);

        }
      }
      return ans;

    }
};
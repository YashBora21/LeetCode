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
    bool levelorder(TreeNode* root,int k){
        queue<TreeNode*> q;
        if(root) q.push(root);
        unordered_set<int>seen;
        
        while(!q.empty()){
            TreeNode *temp=q.front();q.pop();
            int complement=k-temp->val;
            if(seen.find(complement)!=seen.end()){
                return true;
            }
            seen.insert(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);

            
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        return levelorder(root,k);
    }
};
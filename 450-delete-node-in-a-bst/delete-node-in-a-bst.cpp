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
    TreeNode* dfs(TreeNode* root,int key){
        if(root==NULL) return root;
        root->left=dfs(root->left,key);
        if(root->val==key){
            if(root->right==NULL && root->left){
            TreeNode* temp=root->left;
            root->val=temp->val;
            root->left=temp->left;
            root->right=temp->right;
            delete temp;
            }
            else if(root->left==NULL&&root->right){
                TreeNode* temp=root->right;
                root->val=temp->val;
                root->right=temp->right;
                root->left=temp->left;
                delete temp;
            }
            else if(root->right && root->left){
                TreeNode* curr=root->right;
                while(curr->left!=NULL){
                    curr=curr->left;
                }
                root->val=curr->val;
                root->right=dfs(root->right,curr->val);
            }
            else{
                delete root;
                return NULL;
            }
            
        }
        root->right=dfs(root->right,key);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
       return  dfs(root,key);
    }
};
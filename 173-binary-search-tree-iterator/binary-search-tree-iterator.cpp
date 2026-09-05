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
class BSTIterator {
public:
    vector<int>store;
    int index;
    void inorder(TreeNode* &root){
        if(!root)return ;
        inorder(root->left);
        store.push_back(root->val);
        inorder(root->right);

    }
    BSTIterator(TreeNode* root) {
        inorder(root);
        index=0;
    }
    
    int next() {
        return store[index++];
    }
    
    bool hasNext() {
        return index<store.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
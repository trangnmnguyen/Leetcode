/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
    	swapNode(&root->left, &root->right);
    	invertTree(root->left);
    	invertTree(root->right);
        return root;
    }

    void swapNode(TreeNode**l, TreeNode** r) {
    	TreeNode* tmp = *l;
    	*l = *r;
    	*r = tmp;
    }
};
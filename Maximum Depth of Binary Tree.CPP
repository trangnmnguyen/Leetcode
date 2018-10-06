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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxHeight = 0;
        recursive(root, 1, maxHeight);
        return maxHeight;
    }

    void recursive(TreeNode* root, int height, int &maxHeight) {
    	if(!root) return;
    	if(maxHeight < height) maxHeight = height;
    	recursive(root->right, height + 1, maxHeight);
    	recursive(root->left, height + 1, maxHeight);
    	return;
    }
};
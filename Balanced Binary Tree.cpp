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
     bool isBalanced(TreeNode* root) {
    	int flag = 0;
    	if(root == NULL) return true;
        if(abs(recrs(root->left, flag) - recrs(root->right, flag)) <= 1 && !flag) return true;
        return false;
    }

    int recrs(TreeNode* root, int &flag) {
    	if(root == NULL) return 0;
    	if(abs(recrs(root->left, flag) - recrs(root->right, flag)) > 1) flag = 1;
    	return recrs(root->left, flag) > recrs(root->right, flag) ? recrs(root->left, flag) + 1 : recrs(root->right, flag) + 1;
    }
};
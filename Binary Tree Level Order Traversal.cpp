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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        recursive(root, res, 0);
    }

    void recursive(TreeNode* root, vector<vector<int>>&res, height) {
    	while(res.size() < height) res.push_back(vector<int>tmp);
    	res[height].push_back(root->val);
    	recursive(root->right, res, height + 1);
    	recursive(root->left, res, height + 1);
    	return;
    }
};
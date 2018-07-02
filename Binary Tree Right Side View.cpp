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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursive(res, root, 0);
        return res;
    }

    void recursive(vector<int>&res, TreeNode* root, int height) {
    	if(!root) return;
    	if(res.size() <= height) res.push_back(root->val);
    	recursive(res, root->right, height + 1);
    	recursive(res, root->left, height + 1);
    	return;
    }
};
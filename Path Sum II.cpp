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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>res;
        vector<int>tmp;
        recursive(res, root, sum, 0, tmp);
        return res;
    }

    void recursive(vector<vector<int>>&res, TreeNode* root, int sum, int sumtmp, vector<int>tmp) {
    	if(!root) return;
    	sumtmp += root->val;
    	tmp.push_back(root->val);
    	if(!root->left && !root->right) {
    		if(sumtmp == sum) res.push_back(tmp);
    		return;
    	}
    	recursive(res, root->left, sum, sumtmp, tmp);
    	recursive(res, root->right, sum, sumtmp, tmp);
    	return;
    }
};
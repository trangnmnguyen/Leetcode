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
    bool hasPathSum(TreeNode* root, int sum) {
        bool res = false;
        if(!root && sum == 0) return false;
        recursive(root, sum, res, 0);
        return res;
    }

    void recursive(TreeNode* r, int sum, bool &res, int sumtmp) {
    	if(res || !r) return;
    	
    	sumtmp += r->val;
    	
    	if(!r->left && !r->right) {
    		if(sumtmp == sum) res = true;
    	}
    	
    	recursive(r->right, sum, res, sumtmp);
    	recursive(r->left, sum, res, sumtmp);
    	return;
    }
};
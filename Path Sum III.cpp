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
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        recursive(root, sum, res);
        return res;
    }

    void recursive(TreeNode* root, int sum, int &res) {
    	if(!root) return;
    	
    }
};
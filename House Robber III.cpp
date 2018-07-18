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
    int rob(TreeNode* root) {
        int sumOdd = 0, sumEven = root->val, level = 1;
        recursive(root, sumOdd, sumEven, level);
        if(sumEven >= sumOdd) return sumEven;
        return sumOdd;
    }

    void recursive(TreeNode* root, int &sumOdd, int &sumEven, int level) {
    	if(!root) return;

    	if(level % 2 == 1) {
    		sumOdd += root->val;
    	} else {
    		sumEven += root->val;
    	}
    	
    	recursive(root->left, sumOdd, sumEven, level + 1);
    	recursive(root->right, sumOdd, sumEven, level + 1);
    	
    	return;
    }
};
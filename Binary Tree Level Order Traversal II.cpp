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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;	
       	recursive(root, res, 0);
      	reverse(res.begin(), res.end());
       	return res;
    }

    void recursive(TreeNode* root, vector<vector<int>>&res, int height) {
    	if(root == NULL) return;

    	while(res.size() <= height) res.push_back(vector<int>());

        res[height].push_back(root->val);
        
    	recursive(root->left, res, height + 1);
    	recursive(root->right, res, height + 1);
    }
};
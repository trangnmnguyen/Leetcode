class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
    	vector<TreeNode*> res;
    	vector<int>visited(n);
    	for(int i = 0; i < n; i++) visited[i] = 0;
        recursive(res, n visited);
        return res;
    }

    void recursive(vector<TreeNode*> &res, int n, TreeNode* &tmp, vector<int>&visited) {
    	for(int i = 0; i < n; i++) {

    	}
    }
};
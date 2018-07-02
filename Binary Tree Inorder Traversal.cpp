class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int>res;
    	stack<TreeNode*>st;
    	TreeNode* tmpNode = root;
    	while(!st.empty() || tmpNode) {
    		while(tmpNode) {
    			st.push(tmpNode);
    			tmpNode = tmpNode->left;
    		}
    		tmpNode = st.top();
    		st.pop();
    		res.push_back(tmpNode->val);
    		tmpNode = tmpNode->right;
    	}
    	return res;
    }
};
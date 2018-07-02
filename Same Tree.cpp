class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) return q == p;
        return p->val == q->val and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};
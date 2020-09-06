class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;     
    }
    void helper(TreeNode* root, vector<int> &ans) {
        if (root != NULL) {
            if (root->left != NULL) {
                helper(root->left, ans);
            }
            ans.push_back(root->val);
            if (root->right != NULL) {
                helper(root->right, ans);
            }
        }
    }
};
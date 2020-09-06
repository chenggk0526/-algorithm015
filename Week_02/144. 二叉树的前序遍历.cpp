class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }

    void helper(TreeNode* root, vector<int> &ans) {
        if (root != NULL) {
            ans.push_back(root->val);
            if (root->left != NULL) helper(root->left, ans);
            if (root->right != NULL) helper(root->right, ans);
        }
    }
};
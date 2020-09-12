class Solution {
public:
    unordered_map<int, int> index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myTree(preorder, inorder, 0, n - 1, 0, n -1);
    }

    TreeNode* myTree(vector<int>& preorder, vector<int>& inorder, 
    int preleft, int preright, int inleft, int inright) {
        if (preleft > preright || inleft > inright) return nullptr;

        int preorder_root = preleft;
        int inorder_root = index[preorder[preorder_root]];
        TreeNode * root = new TreeNode(preorder[preorder_root]);
        int left_size = inorder_root - inleft;

        root->left = myTree(preorder, inorder, preleft + 1, preleft + left_size, inleft, inorder_root - 1);
        root->right = myTree(preorder, inorder, preleft + left_size + 1, preright, inorder_root + 1, inright);
        return root;
    }
};
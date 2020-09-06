class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }

    void helper(Node* root, vector<int> & ans) {
        if (root != nullptr) {
            ans.push_back(root->val);
            for (auto son : root->children) {
                if (son != nullptr) helper(son, ans);
            }
        }
    } 
};
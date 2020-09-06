class Solution {
    vector< vector<int> > ans;
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root != nullptr) helper(root, 0);  
        return ans;   
    }

    void helper(Node* root, int level) {
        if (ans.size() <= level) ans.push_back({});
        ans[level].push_back(root->val);
        for (auto son : root->children) {
            if (son != nullptr) helper(son, level+1);
        }
    }
};
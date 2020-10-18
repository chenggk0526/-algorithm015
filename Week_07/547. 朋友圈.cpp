class Solution {
public:
    int find(vector<int> &parent, int n){
        if(parent[n] == -1)
            return n;
        return find(parent, parent[n]);
    }

    void Union(vector<int> &parent, int x, int y){
        int rootx = find(parent, x);
        int rooty = find(parent, y);
        if(rootx != rooty)
            parent[rootx] = rooty;
    }

    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> parent(n, -1);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(M[i][j] == 1 && i != j) Union(parent,i,j);                  
            }
        }
        int count = 0;
        for(int i = 0; i < n; ++i)
            if(parent[i] == -1) count++;            
        return count;
    }
};
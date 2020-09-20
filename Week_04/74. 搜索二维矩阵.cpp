class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int index = (right + left) / 2;
            int element = matrix[index / n][index % n];
            if (element == target) return true;
            else if (element > target) right = index - 1;
            else left = index + 1;  
        }
        return false;
    }
};
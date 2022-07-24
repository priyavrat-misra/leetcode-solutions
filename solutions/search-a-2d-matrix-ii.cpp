class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            if (target < matrix[i][j])
                --i;
            else if (target > matrix[i][j])
                ++j;
            else
                return true;
        }
        return false;
    }
};

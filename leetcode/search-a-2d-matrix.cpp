class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const vector<int>& row : matrix) {
            if (target >= *row.begin() and target <= *row.rbegin()) {
                int m, i = 0, j = row.size() - 1;
                while (j >= i) {
                    m = (i + j) >> 1;
                    if (row[m] < target)
                        i = m + 1;
                    else if (row[m] > target)
                        j = m - 1;
                    else
                        return true;
                }
                return false;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int mid, lo = 0, hi = m - 1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (matrix[mid][0] < target)
                lo = mid + 1;
            else if (matrix[mid][0] > target)
                hi = mid - 1;
            else
                return true;
        }
        int row = target < matrix[mid][0] ? mid - 1: mid;
        if (row < 0)
            return false;
        
        lo = 0, hi = n;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (matrix[row][mid] < target)
                lo = mid + 1;
            else
                hi = mid;
        }
        if (hi == n)
            return false;
        
        return matrix[row][hi] == target;
    }
};

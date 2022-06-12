class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 1)
            return matrix[0];
        int n = matrix[0].size();
        
        vector<int> ans;
        int top = 0, right = n - 1, left = 0, bottom = m - 1;
        int dir = 1;
        while (top <= bottom && left <= right) {
            switch (dir) {
                case 1:
                    for (int i = left; i <= right; ++i)
                        ans.push_back(matrix[top][i]);
                    ++top;
                    dir = 2;
                    break;
                case 2:
                    for (int i = top; i <= bottom; ++i)
                        ans.push_back(matrix[i][right]);
                    --right;
                    dir = 3;
                    break;
                case 3:
                    for (int i = right; i >= left; --i)
                        ans.push_back(matrix[bottom][i]);
                    --bottom;
                    dir = 4;
                    break;
                case 4:
                    for (int i = bottom; i >= top; --i)
                        ans.push_back(matrix[i][left]);
                    ++left;
                    dir = 1;
                    break;
            }
        }
        return ans;
    }
};

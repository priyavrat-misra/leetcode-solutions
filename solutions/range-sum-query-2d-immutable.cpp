class NumMatrix {
public:
    vector<vector<int>>& matrix;
    int m, n;
    NumMatrix(vector<vector<int>>& matrix) : matrix(matrix), m(matrix.size()), n(matrix[0].size()) {
        for (int i = 1; i < n; ++i)
            matrix[0][i] += matrix[0][i-1];
        for (int i = 1; i < m; ++i)
            matrix[i][0] += matrix[i-1][0];
        
        for (int r = 1; r < m; ++r)
            for (int c = 1; c < n; ++c)
                matrix[r][c] += matrix[r-1][c] + matrix[r][c-1] - matrix[r-1][c-1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0)
            return matrix[row2][col2];
        else if (row1 == 0)
            return matrix[row2][col2] - matrix[row2][col1-1];
        else if (col1 == 0)
            return matrix[row2][col2] - matrix[row1-1][col2];
        
        return matrix[row2][col2] - matrix[row1-1][col2] - matrix[row2][col1-1] + matrix[row1-1][col1-1];
    }
    
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

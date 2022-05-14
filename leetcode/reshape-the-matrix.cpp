class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.size() * mat[0].size() == r * c) {
            vector<vector<int>> v(r, vector<int>(c));
            int k = 0;
            for (vector<int>& row : mat) {
                for (int& num : row) {
                    v[k/c][k%c] = num;
                    ++k;
                }
            }
            return v;
        } else {
            return mat;
        }
    }
};

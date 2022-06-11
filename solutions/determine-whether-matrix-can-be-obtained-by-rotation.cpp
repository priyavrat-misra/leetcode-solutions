class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target)
            return true;
        
        int n = mat.size();
        for (int r = 0; r < 3; ++r) {
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j)
                    swap(mat[i][j], mat[j][i]);
            
            reverse(mat.begin(), mat.end());
            if (mat == target)
                return true;
        }
        return false;
    }
};

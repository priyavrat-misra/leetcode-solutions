class Solution {
public:
    int m, n;
    int maximalArea(vector<int>& row) {
        vector<int> nsl, nsr;
        stack<pair<int, int>> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && s.top().first >= row[i])
                s.pop();
            if (s.empty())
                nsl.push_back(-1);
            else
                nsl.push_back(s.top().second);
            
            s.push({row[i], i});
        }
        
        while (!s.empty())
            s.pop();
        
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && s.top().first >= row[i])
                s.pop();
            if (s.empty())
                nsr.push_back(n);
            else
                nsr.push_back(s.top().second);
            
            s.push({row[i], i});
        }
        
        int max_area = 0;
        for (int i = 0; i < n; ++i)
            max_area = max(max_area, (nsr[n-i-1] - nsl[i] - 1) * row[i]);
        
        return max_area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<int> curr_row(n);
        for (int i = 0; i < n; ++i)
            curr_row[i] = (matrix[0][i] == '0' ? 0 : 1);
        
        int max_rect = maximalArea(curr_row);
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0')
                    curr_row[j] = 0;
                else
                    curr_row[j] += 1;
            }
            max_rect = max(max_rect, maximalArea(curr_row));
        }
        return max_rect;
    }
};

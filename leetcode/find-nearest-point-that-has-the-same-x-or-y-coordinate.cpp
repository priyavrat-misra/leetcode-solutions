class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min_i = -1, manhattan = INT_MAX, t;
        for (int i = 0; i < points.size(); ++i) {
            t = manhattan;
            if (x == points[i][0] && y == points[i][1])
                manhattan = 0;
            else if (x == points[i][0])
                manhattan = min(manhattan, abs(y - points[i][1]));
            else if (y == points[i][1])
                manhattan = min(manhattan, abs(x - points[i][0]));
            if (t != manhattan)
                min_i = i;
        }
        return min_i;
    }
};

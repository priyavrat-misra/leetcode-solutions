class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int max_diff_h = max(horizontalCuts.front(), h - horizontalCuts.back()), max_diff_v = max(verticalCuts.front(), w - verticalCuts.back());
        
        int size_h = horizontalCuts.size(), size_v = verticalCuts.size();
        for (int i = 1; i < size_h; ++i)
            max_diff_h = max(max_diff_h, horizontalCuts[i] - horizontalCuts[i-1]);
        for (int i = 1; i < size_v; ++i)
            max_diff_v = max(max_diff_v, verticalCuts[i] - verticalCuts[i-1]);
        
        return long(max_diff_h) * max_diff_v % 1000000007;
    }
};

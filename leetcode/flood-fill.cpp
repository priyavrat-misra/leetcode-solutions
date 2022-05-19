class Solution {
public:
    void dfs(vector<vector<int>>& image, const int& sr, const int& sc, int& color, int& newColor) {
        if (image[sr][sc] == color) {
            image[sr][sc] = newColor;
            if (sr > 0)
                dfs(image, sr - 1, sc, color, newColor);
            if (sr < image.size() - 1)
                dfs(image, sr + 1, sc, color, newColor);
            if (sc > 0)
                dfs(image, sr, sc - 1, color, newColor);
            if (sc < image[0].size() - 1)
                dfs(image, sr, sc + 1, color, newColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor)
            dfs(image, sr, sc, color, newColor);
        return image;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int *maxL = new int[n], *maxR = new int[n];
        maxL[0] = height.front();
        for (int i = 1; i < n; ++i)
            maxL[i] = max(maxL[i-1], height[i]);
        
        maxR[n-1] = height.back();
        for (int i = n - 2; i >= 0; --i)
            maxR[i] = max(maxR[i+1], height[i]);
        
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans += min(maxL[i], maxR[i]) - height[i];
        
        delete[] maxL;
        delete[] maxR;
        return ans;
    }
};

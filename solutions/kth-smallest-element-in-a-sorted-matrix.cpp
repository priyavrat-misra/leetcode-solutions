class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxH;
        for (vector<int>& row : matrix)
            for (int& no : row) {
                maxH.push(no);
                if (maxH.size() > k)
                    maxH.pop();
            }
        return maxH.top();
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<pair<int, int>> points;
        multiset<int> pq{0};
        
        for (vector<int>& b : buildings) {
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }
        
        sort(points.begin(), points.end());
        
        int height = 0;
        for (pair<int, int>& point : points) {
            int& curr_point = point.first;
            int& curr_height = point.second;
            if (curr_height < 0)
                pq.insert(-curr_height);
            else
                pq.erase(pq.find(curr_height));
            
            int pq_top = *pq.rbegin();
            if (pq_top != height) {
                height = pq_top;
                ans.push_back({curr_point, height});
            }
        }
        
        return ans;
    }
};

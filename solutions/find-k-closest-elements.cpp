class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        for (int& i : arr) {
            pq.push({abs(x - i), i});
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans(k);
        for (int i = 0; i < k; ++i)
            ans[i] = pq.top().second, pq.pop();
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int& e : arr)
            ++freq[e];
        
        priority_queue<int> maxH;
        for (pair<const int, int>& row : freq)
            maxH.push(row.second);
        
        int h = arr.size()/2, ans = 0, cnt = 0;
        while (cnt < h) {
            cnt += maxH.top();
            maxH.pop();
            ++ans;
        }
        return ans;
    }
};

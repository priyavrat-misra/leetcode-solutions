class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> v(arr.size(), {0, 0});
        int i = 0, b;
        for (int& num : arr) {
            b = 0;
            v[i].second = num;
            while (num) {
                if (num % 2)
                    ++b;
                num >>= 1; 
            }
            v[i].first = b;
            ++i;
        }
        sort(v.begin(), v.end());
        i = 0;
        for (pair<int, int>& p : v) {
            arr[i] = p.second;
            ++i;
        }
        return arr;
    }
};

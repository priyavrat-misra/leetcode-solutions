class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(
            properties.begin(),
            properties.end(),
            [] (vector<int>& a, vector<int>& b) {
                if (a[0] == b[0])
                    return a[1] > b[1];
                
                return a[0] < b[0];
            }
        );
        
        int ans = 0, max_so_far = INT_MIN;
        auto it = properties.rbegin();
        while (it != properties.rend()) {
            if ((*it)[1] < max_so_far)
                ++ans;
            max_so_far = max(max_so_far, (*it)[1]);
            ++it;
        }
        
        return ans;
    }
};

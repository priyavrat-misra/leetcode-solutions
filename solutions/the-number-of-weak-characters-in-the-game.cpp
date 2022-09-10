class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(
            properties.begin(),
            properties.end(),
            [](vector<int>& property1, vector<int>& property2) {
                if (property1[0] == property2[0])
                    return property1[1] > property2[1];
                
                return property1[0] < property2[0];
            }
        );
        
        int ans = 0, max_so_far = INT_MIN;
        auto it = properties.rbegin(), rend = properties.rend();
        while (it != rend) {
            if ((*it)[1] < max_so_far)
                ++ans;
            max_so_far = max(max_so_far, (*it)[1]);
            ++it;
        }
        return ans;
    }
};

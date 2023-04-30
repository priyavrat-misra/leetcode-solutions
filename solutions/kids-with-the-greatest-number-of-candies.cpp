class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = 0;
        for (int& candy : candies)
            mx = mx > candy ? mx : candy;
        
        int n = candies.size();
        vector<bool> res(n);
        for (int i = 0; i < n; ++i)
            res[i] = candies[i] + extraCandies >= mx;
        
        return res;
    }
};

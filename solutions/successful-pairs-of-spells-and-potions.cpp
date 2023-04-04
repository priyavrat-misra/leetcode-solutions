class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        vector<int>::iterator i = potions.begin(), j = potions.end();
        sort(i, j);
        for (int& spell : spells)
            ans.push_back(j - lower_bound(i, j, (success + spell - 1) / spell));
        return ans;
    }
};

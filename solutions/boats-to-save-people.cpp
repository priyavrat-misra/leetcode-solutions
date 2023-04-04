class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        vector<int>::iterator i = people.begin(), j = people.end();
        sort(i, j);
        while (i < j) {
            --j;
            if (*i + *j <= limit)
                ++i;
            ++ans;
        }
        return ans;
    }
};

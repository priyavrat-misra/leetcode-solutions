class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if (temperatures.size() == 1)
            return {0};
        
        int n = temperatures.size(), hottest = 0;
        vector<int> ans(n);
        for (int currDay = n - 1; currDay >= 0; --currDay) {
            int currTemp = temperatures[currDay];
            if (currTemp >= hottest) {
                hottest = currTemp;
                continue;
            }
            
            int days = 1;
            while (temperatures[currDay + days] <= currTemp)
                days += ans[currDay + days];
            
            ans[currDay] = days;
        }
        return ans;
    }
};

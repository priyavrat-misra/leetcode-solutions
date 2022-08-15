class Solution {
public:
    int romanToInt(string& s) {
        unordered_map<char, int> map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int ans = 0, i = s.size() - 1;
        while (i > 0) {
            if (map[s[i]] > map[s[i-1]]) {
                ans += map[s[i]] - map[s[i-1]];
				i -= 2;
            } else {
                ans += map[s[i]];
				i -= 1;
			}
        }
        
        if (i == 0)
            ans += map[s[i]];
        
        return ans;
    }
};

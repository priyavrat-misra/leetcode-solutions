class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> have, need;
        for (int& num: nums)
            ++have[num];
        
        for (int& num: nums) {
            if (have[num] == 0)
                continue;
            
            --have[num];
            if (need[num - 1] > 0) {   
                --need[num - 1];
                ++need[num];
            } else if (have[num + 1] > 0 && have[num + 2] > 0) {
                --have[num + 1];
                --have[num + 2];
                ++need[num + 2];
            } else {   
                return false;
            }
        }
        return true;
    }
};

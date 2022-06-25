class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> vec(nums);
        for (auto it = vec.begin() + 1; it != vec.end(); ++it)
            *it += *(it - 1);
        
        int s = nums.size(), i = 0, leftsum = 0;
        while (i < s) {
            if (leftsum == vec[s-1] - vec[i])
                return i;
            leftsum += nums[i++];
        }
        return -1;
    }
};

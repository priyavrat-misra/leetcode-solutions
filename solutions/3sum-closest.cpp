class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest = nums[0] + nums[1] + nums[2];
        for (int first = 0; first < n - 2; ++first) {
            int second = first + 1;
            int third = n - 1;
            while (second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if (sum == target)
                    return sum;
                else if (sum > target)
                    --third;
                else
                    ++second;
                
                if (abs(target - sum) < abs(target - closest))
                    closest = sum;
            }
        }
        return closest;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        vector<int> v(2);
        vector<pair<int, int>> arr(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            arr[i].first = nums[i];
            arr[i].second = i;
        }
        sort(arr.begin(), arr.end());
        while (i < j) {
            if (arr[i].first + arr[j].first < target)
                ++i;
            else if (arr[i].first + arr[j].first > target)
                --j;
            else {
                v[0] = arr[i].second;
                v[1] = arr[j].second;
                break;
            }
        }
        return v;
    }
};

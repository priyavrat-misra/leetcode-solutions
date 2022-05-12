class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        vector<int> v(2);
        while (i < j) {
            if (numbers[i] + numbers[j] < target) {
                ++i;
            } else if (numbers[i] + numbers[j] > target) {
                --j;
            } else {
                v[0] = i + 1;
                v[1] = j + 1;
                break;
            }
        }
        return v;
    }
};

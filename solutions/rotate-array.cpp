class Solution {
public:    
    void reverse(vector<int>::iterator i, vector<int>::iterator j) {
        while (i < j) {
            swap(*i, *j);
            ++i;
            --j;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (nums.size() > 1 && k) {
            reverse(nums.begin(), nums.end() - 1);
            reverse(nums.begin(), nums.begin() + k - 1);
            reverse(nums.begin() + k, nums.end() - 1);
        }
    }
};

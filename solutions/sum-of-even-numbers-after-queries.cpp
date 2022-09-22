class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int even_sum = 0;
        for (int& i : nums)
            if (i % 2 == 0)
                even_sum += i;
        
        vector<int> ans;
        for (vector<int>& query : queries) {
            int &val = query[0], &index = query[1];
            if (nums[index] % 2 == 0)
                even_sum -= nums[index];
            
            nums[index] += val;
            if (nums[index] % 2 == 0)
                even_sum += nums[index];
            
            ans.push_back(even_sum);
        }
        return ans;
    }
};

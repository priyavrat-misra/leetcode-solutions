class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int i = min_element(nums.begin(), nums.end()) - nums.begin();
        int j = max_element(nums.begin(), nums.end()) - nums.begin();
        
        if (i > j)
            swap(i, j);
        
        /**
         *             (i)             (j)
         * [ _ _ _ _ _ min _ _ _ _ _ _ max _ _ _ _ _ _ ] 
         *   <-- a -->      <-- b -->       <-- c -->
         *  <------------------- n ------------------->
         * 
         * Case 1 : No. of deletion = (a + c) = ((i+1) + (n-j)),
         * Case 2 : No. of deletion = (a + b) = (j+1)
         * Case 3 : No. of deletion = (b + c) = (n - i)
         */
        
        return min({i + 1 + n - j, j + 1, n - i});
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> m;
        for (int i = 0; i < nums2.size(); ++i) {
            while (!stk.empty() && stk.top() < nums2[i]) {
                m[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
            m[nums2[i]] = -1;
        }
        for (int& e : nums1)
            e = m[e];
        return nums1;
    }
};

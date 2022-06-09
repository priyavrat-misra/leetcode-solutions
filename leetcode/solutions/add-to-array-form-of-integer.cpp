class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        int m = num.size();
        vector<int> ans;
        while (m || k || carry) {
            if (m)
                carry += num[--m];
            if (k)
                carry += k % 10;
            
            ans.push_back(carry % 10);
            carry /= 10;
            k /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

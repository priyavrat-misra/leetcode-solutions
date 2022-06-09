class Solution {
public:
    string addBinary(string& a, string& b) {
        if (a.size() < b.size())
            return addBinary(b, a);
        int m = a.size(), n = b.size();
        int carry = 0;
        string ans;
        while (n || m || carry) {
            if (n)
                carry += a[--m] + b[--n] - 2 * '0';
            else if (m)
                carry += a[--m] - '0';
            
            ans += carry % 2 + '0';
            carry >>= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

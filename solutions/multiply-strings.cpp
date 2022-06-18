class Solution {
public:
	string multiply(string& a, string& b) {
		int m = a.size(), n = b.size();
		if (m == 1 && a[0] == '0' || n == 1 && b[0] == '0')
            return "0";
		if (m < n)
			return multiply(b, a);
		int carry = 0, prod, i = n;
		vector<string> partial_prods;
		while (i--) {
			string partial_prod(n - i - 1, '0');
			for (int j = m - 1; j >= 0; --j) {
				prod = (a[j]-'0') * (b[i]-'0');
				if (carry)
					prod += carry;
				partial_prod.push_back((prod % 10) + '0');
				carry = prod/10;
			}
			if (carry)
				partial_prod.push_back(carry + '0');
			carry = 0;
			partial_prods.push_back(partial_prod + string(m + n - partial_prod.size(), '0'));
		}

		string ans;
		int l = partial_prods[0].size();
		for (int i = 0; i < l; ++i) {
			for (int j = 0; j < n; ++j)
				carry += partial_prods[j][i] - '0';
			ans.push_back((carry % 10) + '0');
			carry /= 10;
		}
		if (*ans.rbegin() == '0')
			ans.pop_back();
		if (carry)
			ans.push_back(carry + '0');

		reverse(ans.begin(), ans.end());
		return ans;
	}
};

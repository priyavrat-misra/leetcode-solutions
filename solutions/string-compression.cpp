class Solution {
	public:
		int compress(vector<char>& chars) {
			int n = chars.size();
			if (n < 2)
				return n;

			int i = 0, j = 0;
			while (i < n) {
				chars[j] = chars[i];
				int count = 0;
				while (i < n && chars[i] == chars[j])
					++count, ++i;
				if (count == 1)
					++j;
				else {
					string s = to_string(count);
					for (char& c : s)
						chars[++j] = c;
					++j;
				}
			}
			return j;
		}
};

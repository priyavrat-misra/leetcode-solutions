class Solution {
	public:
		int computeHash(string& str, int& size) {
			int hash = 0;
			for (int i = 0; i < size; ++i)
				hash = (hash * 26 + (str[i] - 'a')) % 101;
			return hash;
		}

		int strStr(string haystack, string needle) {
			int n = needle.size();
			if (n == 0)
				return 0;
			int h = haystack.size();
			if (h < n)
				return -1;

			int needle_hash = computeHash(needle, n);
			int window_hash = computeHash(haystack, n);

			int msv = 1;
			for (int i = 0; i < n - 1; ++i)
				msv = (msv * 26) % 101;

			for (int i = 0; i < h - n + 1; ++i) {
				if (window_hash == needle_hash && haystack.substr(i, n) == needle)
					return i;
				window_hash = ((window_hash - (haystack[i] - 'a') * msv) * 26 + (haystack[i + n] - 'a')) % 101;
				if (window_hash < 0)
					window_hash += 101;
			}
			return -1;
		}
};

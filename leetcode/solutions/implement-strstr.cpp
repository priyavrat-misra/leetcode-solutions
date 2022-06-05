class Solution {
public:
    int computeHash(string& str, int& size) {
        int hash = 0;
        for (int i = 0; i < size; ++i)
            hash = (hash * 26 + (str[i] - 'a')) % 101;
        return hash;
    }
    
    int strStr(string& haystack, string& needle) {
        int n = needle.size();
        if (n == 0)
            return 0;
        int h = haystack.size();
        if (n > h)
            return -1;
        
        int msv = 1;
        for (int i = 0; i < n - 1; ++i)
            msv = (msv * 26) % 101;
        
        int needle_hash = computeHash(needle, n);
        int hstk_hash = computeHash(haystack, n);
        for (int i = 0; i < h - n + 1; ++i) {
            if (needle_hash == hstk_hash && needle == haystack.substr(i, n))
                    return i;
            hstk_hash = (((hstk_hash - (haystack[i] - 'a') * msv % 101) * 26 % 101) + (haystack[i+n] - 'a')) % 101;
            if (hstk_hash < 0)
                hstk_hash += 101;
        }
        return -1;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size())
            return false;
        if (!s.size())
            return true;
        
        for (auto it1 = s.begin(), it2 = t.begin(); it2 != t.end(); ++it2)
            if (*it1 == *it2)
                if (++it1 == s.end())
                    return true;
        
        return false;
    }
};

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        stringstream ss(path);
        string dir;
        while (getline(ss, dir, '/')) {
            if (dir.empty() || dir == ".")
                continue;
            else if (dir == "..") {
                if (!stk.empty())
                    stk.pop_back();
            } else
                stk.push_back(dir);
        }
        string res;
        for (string& dir : stk)
            res += "/" + dir;
        return res.empty() ? "/" : res;
    }
};

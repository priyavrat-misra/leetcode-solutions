class Solution {
public:
    void perm(string& op, string ip, vector<string>& res) {
        if (ip.empty()) {
            res.push_back(op);
            return;
        }
        if (isalpha(ip.front())) {
            string op1 = op, op2 = op;
            op1.push_back(ip.front());
            op2.push_back(ip.front() ^ ' ');
            ip.erase(ip.begin());
            perm(op1, ip, res);
            perm(op2, ip, res);
        } else {
            op.push_back(ip.front());
            ip.erase(ip.begin());
            perm(op, ip, res);
        }
    }
    
    vector<string> letterCasePermutation(string& s) {
        string op;
        vector<string> res;
        perm(op, s, res);
        return res;
    }
};

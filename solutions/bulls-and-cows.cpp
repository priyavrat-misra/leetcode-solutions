class Solution {
public:
    string getHint(string& secret, string& guess) {
        if (secret.empty())
            return "0A0B";
        vector<int> s(10), g(10);
        int n = secret.size(), x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i])
                ++x;
            else {
                ++s[secret[i]-'0'];
                ++g[guess[i]-'0']; 
            }
        }
        for (int i = 0; i < 10; ++i)
            y += min(s[i], g[i]);
        
        return to_string(x) + 'A' + to_string(y) + 'B';
    }
};

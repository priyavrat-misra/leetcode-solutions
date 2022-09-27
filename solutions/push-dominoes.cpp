class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> LR(n, 0), RL(n, 0);
        
        for (int i = 0, cnt = 0; i < n; ++i) {
            if (dominoes[i] == '.' && cnt)
                LR[i] = cnt++;
            else if (dominoes[i] == 'R')
                cnt = 1;
            else
                cnt = 0;
        }

        for (int i = n - 1, cnt = 0; i >= 0; --i) {
            if (dominoes[i] == '.' && cnt)
                RL[i] = cnt++;
            else if (dominoes[i] == 'L')
                cnt = 1;
            else
                cnt = 0;
        }
        
        for (int i = 0; i < n; ++i) {
            if (!LR[i] && RL[i])
                dominoes[i] = 'L';
            else if (LR[i] && !RL[i])
                dominoes[i] = 'R';
            else if (LR[i] > RL[i])
                dominoes[i] = 'L';
            else if (LR[i] < RL[i])
                dominoes[i] = 'R';
        }
        
        return dominoes;
    }
};

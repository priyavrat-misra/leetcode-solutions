class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> freq(9, -1);
        for (const vector<char>& row : board) {
            for (const char& c : row)
                if(c != '.' && ++freq[c - '0' - 1])
                    return false;
            
            fill(freq.begin(), freq.end(), -1);
        }
        
        char c;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j)
                if ((c = board[j][i]) != '.' && ++freq[c - '0' - 1])
                    return false;
            
            fill(freq.begin(), freq.end(), -1);
        }
        
        for (int h = 0; h < 3; ++h)
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j)
                    for (int k = 0; k < 3; ++k)
                        if ((c = board[h*3+j][i*3+k]) != '.' && ++freq[c - '0' - 1])
                            return false;
                
                fill(freq.begin(), freq.end(), -1);
            }
        
        return true;
    }
};

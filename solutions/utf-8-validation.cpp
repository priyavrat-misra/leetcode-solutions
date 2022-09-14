class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int bytesToProcess = 0;
        int one = 1 << 7, zero = 1 << 6;
        for (int& byte : data) {
            if (bytesToProcess == 0) {
                int mask = 1 << 7;
                while (byte & mask)
                    ++bytesToProcess, mask >>= 1;
                
                if (bytesToProcess == 0)
                    continue;
                
                if (bytesToProcess > 4 || bytesToProcess == 1)
                    return false;
            } else {
                if (!(byte & one && !(byte & zero)))
                    return false;
            }
            --bytesToProcess;
        }
        return bytesToProcess == 0;
    }
};

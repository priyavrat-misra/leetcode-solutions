class AuthenticationManager {
public:
    int timeToLive;
    unordered_map<string, int> m;
    
    AuthenticationManager(int timeToLive) : timeToLive(timeToLive) {}
    
    void generate(string tokenId, int currentTime) {
        m[tokenId] = currentTime + timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        if (m.count(tokenId) && m[tokenId] > currentTime)
            m[tokenId] = currentTime + timeToLive;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (pair<const string, int>& row : m)
            if (row.second > currentTime)
                ++count;
        
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */

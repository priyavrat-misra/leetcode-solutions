class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string map[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> codes;
        for (string& word : words) {
            string morse;
            for (char& c : word)
                morse += map[c-'a'];
            
            codes.insert(morse);
        }
        return codes.size();
    }
};

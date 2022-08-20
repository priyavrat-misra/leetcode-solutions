class Solution {
public:
    string sortSentence(string& s) {
        vector<string> words(9);
        istringstream strstream(s);
        string word;
        while (getline(strstream, word, ' '))
            words[word.back() - '1'] = word;
        
        string sentence;
        for (string& word : words) {
            if (word == "")
                continue;
            word.back() = ' ';
            sentence += word;
        }
        sentence.pop_back();
        return sentence;
    }
};

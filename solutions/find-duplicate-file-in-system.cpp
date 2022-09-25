class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> files;
        vector<vector<string>> ans;
        
        for (string& path : paths) {
            stringstream ss(path);
            string pwd, s;
            getline(ss, pwd, ' ');
            while (getline(ss, s, ' ')) {
                string file = pwd + '/' + s.substr(0, s.find('('));
		string content = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
		files[content].push_back(file);
            }
        }
        
        for (const pair<string, vector<string>>& file : files)
            if (file.second.size() > 1)
                ans.push_back(file.second);
        
        return ans;
    }
};

class Solution {
public:
    unordered_map<char, char> parent;
 	int find(char& x) {
 		if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
 	}
    
    bool equationsPossible(vector<string>& equations) {
        for(string& x: equations) {
            parent[x[0]] = x[0];
            parent[x[3]] = x[3];
        }

        for(string& eq: equations)
            if (eq[1] == '=') {
                char x = find(eq[0]);
                char y = find(eq[3]);    
                parent[y] = x;
            }
        
        for(string& eq: equations)
            if(eq[1] == '!' && find(eq[0]) == find(eq[3]))
                return false;
        
        return true;
    }
};

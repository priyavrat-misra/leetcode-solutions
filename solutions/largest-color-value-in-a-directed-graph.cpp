class Solution {
public:
    unordered_set<int> path;
    int dfs(int& node, string& colors, vector<vector<int>>& adj_list, vector<bool>& is_visited, vector<vector<int>>& cnt) {
        if (path.count(node))
            return INT_MAX;
        if (!is_visited[node]) {
            is_visited[node] = true;
            path.insert(node);
            for (int& neighbor : adj_list[node]) {
                if (dfs(neighbor, colors, adj_list, is_visited, cnt) == INT_MAX)
                    return INT_MAX;
                for (int col = 0; col < 26; ++col)
                    cnt[node][col] = max(cnt[node][col], cnt[neighbor][col]);
            }
            ++cnt[node][colors[node] - 'a'];
            path.erase(node);
        }
        return cnt[node][colors[node] - 'a'];
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj_list(n);
        for (vector<int>& edge : edges)
            adj_list[edge[0]].push_back(edge[1]);
        
        vector<bool> is_visited(n, false);
        vector<vector<int>> cnt(n, vector<int>(26, 0));
        int res = 0;
        for (int i = 0; i < n; ++i)
            res = max(res, dfs(i, colors, adj_list, is_visited, cnt));
        
        return res == INT_MAX ? -1 : res;
    }
};

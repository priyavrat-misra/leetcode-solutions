class Solution {
public:
    int ans = 0;
    void dfs(int vertex, vector<vector<pair<int, bool>>>& adj_list, vector<bool>& is_visited) {
        is_visited[vertex] = true;
        for (pair<int, bool>& neighbor : adj_list[vertex])
            if (!is_visited[neighbor.first]) {
                dfs(neighbor.first, adj_list, is_visited);
                if (neighbor.second)
                    ++ans;
            }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> adj_list(n);
        for (vector<int>& edge : connections) {
            adj_list[edge[0]].push_back({edge[1], true});
            adj_list[edge[1]].push_back({edge[0], false});
        }
        vector<bool> is_visited(n);
        dfs(0, adj_list, is_visited);
        return ans;
    }
};
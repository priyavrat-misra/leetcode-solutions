class Solution {
public:
    int bfs(int& n, vector<vector<pair<int, int>>>& adj_list) {
        int ans = numeric_limits<int>::max();
        vector<bool> is_visited(n + 1);
        queue<int> q;
        q.push(1);
        is_visited[1] = true;
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            for (pair<int, int>& edge : adj_list[vertex]) {
                ans = min(ans, edge.second);
                if (!is_visited[edge.first])
                    q.push(edge.first), is_visited[edge.first] = true;
            }
        }
        return ans;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj_list(n + 1);
        for (vector<int>& road : roads) {
            adj_list[road[0]].push_back({road[1], road[2]});
            adj_list[road[1]].push_back({road[0], road[2]});
        }
        return bfs(n, adj_list);
    }
};
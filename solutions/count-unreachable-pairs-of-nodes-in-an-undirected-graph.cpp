class Solution {
public:
    void dfs(int& vertex, vector<vector<int>>& adj_list, vector<bool>& is_visited, int& sizeOfComponent) {
        is_visited[vertex] = true;
        for (int& neighbor : adj_list[vertex])
            if (!is_visited[neighbor])
                ++sizeOfComponent, dfs(neighbor, adj_list, is_visited, sizeOfComponent);
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        if (edges.empty())
            return (long long) n * (n - 1) / 2;
        
        vector<vector<int>> adj_list(n);
        for (vector<int>& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        vector<bool> is_visited(n);
        long long numPairs = 0;
        long long remainingNodes = n;
        for (int i = 0; i < n; ++i) {
            if (!is_visited[i]) {
                int sizeOfComponent = 1;
                dfs(i, adj_list, is_visited, sizeOfComponent);
                numPairs += sizeOfComponent * (remainingNodes -= sizeOfComponent);
            }
        }
        return numPairs;
    }
};
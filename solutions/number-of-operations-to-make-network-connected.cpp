class Solution {
public:
    void dfs(int& vertex, vector<vector<int>>& adj_list, vector<bool>& is_visited) {
        is_visited[vertex] = true;
        for (int& neighbor : adj_list[vertex])
            if (!is_visited[neighbor])
                dfs(neighbor, adj_list, is_visited);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int numEdges = connections.size();
        if (numEdges < n - 1)
            return -1;
        
        vector<vector<int>> adj_list(n);
        for (vector<int>& edge : connections) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        
        int numComponents = 0;
        vector<bool> is_visited(n);
        for (int vertex = 0; vertex < n; ++vertex)
            if (!is_visited[vertex])
                dfs(vertex, adj_list, is_visited), ++numComponents;
        
        return numComponents - 1;
    }
};
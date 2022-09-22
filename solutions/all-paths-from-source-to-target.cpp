class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    int target;
    
    void dfs(vector<vector<int>>& graph, const int& curr_node) {
        path.push_back(curr_node);
        if (curr_node == target)
            ans.push_back(path);
        else
            for (int& node : graph[curr_node])
                dfs(graph, node);
        
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size() - 1;
        dfs(graph, 0);
        return ans;
    }
};

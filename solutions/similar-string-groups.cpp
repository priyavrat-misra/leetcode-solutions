class Solution {
public:
    int m, n;

    bool isSimilar(string& a, string& b) {
        int diff = 0;
        for (int i = 0; i < m; ++i)
            if (a[i] != b[i])
                ++diff;
        return diff == 0 || diff == 2;
    }

    void dfs(int& node, vector<vector<int>>& adjList, vector<bool>& isVisited) {
        isVisited[node] = true;
        for (int& neighbor : adjList[node])
            if (!isVisited[neighbor])
                dfs(neighbor, adjList, isVisited);
    }

    int numSimilarGroups(vector<string>& strs) {
        n = strs.size();
        m = strs[0].size();
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (isSimilar(strs[i], strs[j]))
                    adjList[i].push_back(j), adjList[j].push_back(i);

        vector<bool> isVisited(n);
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (!isVisited[i])
                dfs(i, adjList, isVisited), ++ans;

        return ans;
    }
};

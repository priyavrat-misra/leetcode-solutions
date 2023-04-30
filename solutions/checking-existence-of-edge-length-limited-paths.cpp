class Solution {
public:
    bool static compare(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    int find(int& i, vector<int>& parent) {
        if (i == parent[i])
            return i;
        return find(parent[i], parent);
    }

    void _union(int& u, int& v, vector<int>& parent, vector<int>& rank) {
        int u_parent = find(u, parent);
        int v_parent = find(v, parent);
        if (u_parent == v_parent)
            return;
        if (rank[u_parent] > rank[v_parent])
            parent[v_parent] = u_parent;
        else if (rank[u_parent] < rank[v_parent])
            parent[u_parent] = v_parent;
        else
            parent[u_parent] = v_parent, ++rank[v_parent];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int edgeListCount = edgeList.size();
        sort(edgeList.begin(), edgeList.end(), compare);

        int queriesCount = queries.size();
        for (int i = 0; i < queriesCount; ++i)
            queries[i].push_back(i);
        sort(queries.begin(), queries.end(), compare);

        vector<int> parent(n), rank(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
        vector<bool> result(queriesCount);
        for (int i = 0, j = 0; i < queriesCount; ++i) {
            while (j < edgeListCount && edgeList[j][2] < queries[i][2])
                _union(edgeList[j][0], edgeList[j][1], parent, rank), ++j;

            result[queries[i][3]] = find(queries[i][0], parent) == find(queries[i][1], parent);
        }
        return result;
    }
};

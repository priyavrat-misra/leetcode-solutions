class DSU {
public:
    int components;
    vector<int> parent, rank;

    DSU(int n) : parent(n + 1), rank(n + 1), components(n) {
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int& i) {
        if (i == parent[i])
            return i;
        return find(parent[i]);
    }

    bool _union(int& u, int& v) {
        int u_parent = find(u);
        int v_parent = find(v);
        if (u_parent == v_parent)
            return false;
        if (rank[u_parent] > rank[v_parent])
            parent[v_parent] = u_parent;
        else if (rank[u_parent] < rank[v_parent])
            parent[u_parent] = v_parent;
        else
            parent[u_parent] = v_parent, ++rank[v_parent];

        --components;
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n), Bob(n);

        int minEdges = 0;
        for (vector<int>& edge : edges)
            if (edge[0] == 3)
                minEdges += Alice._union(edge[1], edge[2]) | Bob._union(edge[1], edge[2]);

        for (vector<int>& edge : edges) {
            if (edge[0] == 1)
                minEdges += Alice._union(edge[1], edge[2]);
            else
                minEdges += Bob._union(edge[1], edge[2]);
        }

        if (Alice.components == 1 && Bob.components == 1)
            return edges.size() - minEdges;

        return -1;
    }
};

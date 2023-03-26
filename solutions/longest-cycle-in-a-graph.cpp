class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int ans = -1;
        int time = 1;
        int n = edges.size();
        vector<int> time_visited(n);
        for (int i = 0; i < n; ++i) {
            if (!time_visited[i]) {
                int vertex = i;
                const int start_time = time;
                while (vertex != -1 && !time_visited[vertex]) {
                    time_visited[vertex] = time++;
                    vertex = edges[vertex];
                }
                if (vertex != -1 && time_visited[vertex] >= start_time)
                    ans = max(ans, time - time_visited[vertex]);
            }
        }
        return ans;
    }
};
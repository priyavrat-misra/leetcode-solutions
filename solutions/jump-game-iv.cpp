class Solution {
	public:
		int minJumps(vector<int>& arr) {
			int n = arr.size();
			if (n == 1)
				return 0;

			unordered_map<int, vector<int>> indices;
			for (int i = 0; i < n; ++i)
				indices[arr[i]].push_back(i);

			queue<int> q;
			vector<bool> visited(n);
			q.push(0);
			visited[0] = true;
			int steps = 0;
			while (!q.empty()) {
				int size = q.size();
				while (size--) {
					int currIndex = q.front();
					q.pop();
					if (currIndex == n - 1)
						return steps;
					vector<int>& nextIndices = indices[arr[currIndex]];
					nextIndices.push_back(currIndex - 1);
					nextIndices.push_back(currIndex + 1);
					for (int index : nextIndices) {
						if (index >= 0 && index < n && !visited[index]) {
							q.push(index);
							visited[index] = true;
						}
					}
					nextIndices.clear();
				}
				++steps;
			}
			return -1;
		}
};

class Solution {
	public:
		int possibleK(vector<int>& piles, int& k) {
			int timeTaken = 0;
			for (int& pile : piles)
				timeTaken += (pile % k ? pile / k + 1 : pile / k);
			return timeTaken;
		}

		int minEatingSpeed(vector<int>& piles, int h) {
			int minK = 1;
			int maxK = *max_element(piles.begin(), piles.end());
			int mid;
			while (minK < maxK) {
				mid = minK + (maxK - minK) / 2;
				if (possibleK(piles, mid) <= h)
					maxK = mid;
				else
					minK = mid + 1;
			}
			return minK;
		}
};

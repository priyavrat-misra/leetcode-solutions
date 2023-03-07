class Solution {
	public:
		long long numOfTripsForTime(vector<int>& tripTimes, long long& givenTime) {
			long long totalTrips = 0;
			for (int& tripTime : tripTimes)
				totalTrips += givenTime / tripTime;
			return totalTrips;
		}

		long long minimumTime(vector<int>& time, int totalTrips) {
			long long lowestTime = *min_element(time.begin(), time.end());
			long long highestTime = totalTrips * lowestTime;
			long long mid;
			while (lowestTime < highestTime) {
				mid = lowestTime + (highestTime - lowestTime) / 2;
				if (numOfTripsForTime(time, mid) >= totalTrips)
					highestTime = mid;
				else
					lowestTime = mid + 1;
			}
			return lowestTime;
		}
};

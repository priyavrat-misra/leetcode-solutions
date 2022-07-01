class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),
             boxTypes.end(),
             [](vector<int>& first, vector<int>& second) {
                 return first[1] > second[1];
             }
            );
        int ans = 0, i = 0, numBoxes = boxTypes.size();
        while (truckSize && i < numBoxes) {
            if (truckSize < boxTypes[i][0]) {
                ans += truckSize * boxTypes[i][1];
                truckSize = 0;
                continue;
            }
            ans += boxTypes[i][0] * boxTypes[i][1];
            truckSize -= boxTypes[i][0];
            ++i;
        }
        return ans;
    }
};

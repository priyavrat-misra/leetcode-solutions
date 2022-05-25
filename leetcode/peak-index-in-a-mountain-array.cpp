class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int m, i = 0, j = arr.size() - 1;
        while (i < j) {
            m = i + (j - i) / 2;
            if (arr[m] < arr[m + 1])
                i = m + 1;
            else
                j = m;
        }
        return i;
    }
};

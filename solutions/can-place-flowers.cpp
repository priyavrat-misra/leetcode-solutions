class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0;
        int count = 1;
        for (int& flower : flowerbed) {
            if (!flower)
                ++count;
            else
                ans += (count - 1) / 2, count = 0;
        }
        ans += count / 2;
        return n <= ans;
    }
};
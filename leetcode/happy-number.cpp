class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int sum, d;
        while (sum != 1) {
            sum = 0;
            while (n > 0) {
                d = n % 10;
                n /= 10;
                sum += d * d;
            }
            n = sum;
            if (s.count(sum))
                return false;
            else
                s.insert(sum);
        }
        return true;
    }
};

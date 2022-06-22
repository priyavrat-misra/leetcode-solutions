class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills[0] != 5)
            return false;
        
        int five = 0, ten = 0;
        for (int& bill : bills)
            switch (bill) {
                case 5:
                    ++five;
                    break;
                case 10:
                    if (five) {
                        --five;
                        ++ten;
                    } else
                        return false;
                    break;
                case 20:
                    if (five && ten) {
                        --five;
                        --ten;
                    } else if (five > 2)
                        five -= 3;
                    else
                        return false;
                    break;
            }
        return true;
    }
};

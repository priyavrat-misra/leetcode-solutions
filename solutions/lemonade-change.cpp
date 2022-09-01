class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills.front() != 5)
            return false;
        
        int five = 0, ten = 0;
        for (int& bill : bills) {
            switch (bill) {
                case 5:
                    ++five;
                    break;
                case 10:
                    if (five)
                        ++ten, --five;
                    else
                        return false;
                    break;
                case 20:
                    if (ten && five)
                        --ten, --five;
                    else if (five > 2)
                        five -= 3;
                    else
                        return false;
                    break;
            }
        }
        return true;
    }
};

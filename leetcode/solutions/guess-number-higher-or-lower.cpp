/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int i = 1, j = n, pick, x;
        while (i <= j) {
            pick = i + (j - i) / 2;
            x = guess(pick);
            if (x < 0)
                j = pick - 1;
            else if (x > 0)
                i = pick + 1;
            else
                return pick;
        }
        return -1;
    }
};

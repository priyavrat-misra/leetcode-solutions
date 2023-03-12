class Solution {
public:
    void qsort(int* a, int n) {
        if (n > 1) {
            swap(a[rand() % n], a[0]);

            int i = 0, j = 1;
            while (j < n) {
                if (a[0] > a[j])
                    swap(a[i+1], a[j]), ++i, ++j;
                else
                    ++j;
            }
	    
	    swap(a[i], a[0]);
            qsort(a, i);
            qsort(a + i + 1, n - i - 1);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        srand(clock());
        qsort(&nums[0], nums.size());
        return nums;
    }
};
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int freq[1001]{0};
        for (int& item : arr1)
            ++freq[item];
        
        int pos = 0;
        for (int& item : arr2)
            while (freq[item])
                arr1[pos++] = item, --freq[item];
        
        for (int item = 0; item < 1001; ++item)
            while (freq[item])
                arr1[pos++] = item, --freq[item];
        
        return arr1;
    }
};

class MyCalendarThree {
public:
    map<int, int> diff;
    MyCalendarThree() {}
    
    int book(int start, int end) {
        ++diff[start];
        --diff[end];
        int ans = 0, curr = 0;
        for (pair<const int, int>& row : diff) {
            curr += row.second;
            ans = max(ans, curr);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

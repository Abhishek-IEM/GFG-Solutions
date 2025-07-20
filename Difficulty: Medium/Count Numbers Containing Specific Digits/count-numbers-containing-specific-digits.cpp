class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        unordered_set<int> bad(arr.begin(), arr.end());
        vector<int> good;
        for (int d = 0; d <= 9; ++d) {
            if (!bad.count(d)) {
                good.push_back(d);
            }
        }
    
        int total = 0;
        if (n == 1) {
            total = 9;
        } else {
            total = 9;
            for (int i = 1; i < n; ++i) {
                total *= 10;
            }
        }
    
        int count_no_bad = 0;
        int first_digit_options = 0;
        for (int d : good) {
            if (d != 0) {
                first_digit_options++;
            }
        }
        if (n == 1) {
            count_no_bad = first_digit_options;
        } else {
            int total_good = good.size();
            count_no_bad = first_digit_options;
            for (int i = 1; i < n; ++i) {
                count_no_bad *= total_good;
            }
        }
    
        return total - count_no_bad;
    }
};

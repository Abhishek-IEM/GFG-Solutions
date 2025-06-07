class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int n = a1.size();
        unordered_map<int, int> diff_map;
        int max_len = 0;
        int pre_sum1 = 0, pre_sum2 = 0;
    
        for (int i = 0; i < n; i++) {
            pre_sum1 += a1[i];
            pre_sum2 += a2[i];
    
            int curr_diff = pre_sum1 - pre_sum2;
    
            if (curr_diff == 0) {
                max_len = i + 1;
            } else if (diff_map.find(curr_diff) != diff_map.end()) {
                max_len = max(max_len, i - diff_map[curr_diff]);
            } else {
                diff_map[curr_diff] = i;
            }
        }
    
        return max_len;
    }
};
class Solution {
  public:
    vector<vector<int>> res;

    void backtrack(int n, int k, int start, vector<int>& curr) {
        if (n == 0 && k == 0) {
            res.push_back(curr);
            return;
        }
        if (n < 0 || k < 0) return;
    
        for (int i = start; i <= 9; i++) {
            curr.push_back(i);
            backtrack(n - i, k - 1, i + 1, curr);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(int n, int k) {
        res.clear();
        vector<int> curr;
        backtrack(n, k, 1, curr);
        return res;
    }
};
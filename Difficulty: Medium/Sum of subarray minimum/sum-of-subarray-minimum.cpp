class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        const int MOD = 1e9 + 7; // if needed, else remove
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s;
    
        // Calculate left
        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (!s.empty() && arr[s.top()] > arr[i]) {
                count += left[s.top()];
                s.pop();
            }
            left[i] = count;
            s.push(i);
        }
    
        // Clear the stack for reuse
        while (!s.empty()) s.pop();
    
        // Calculate right
        for (int i = n - 1; i >= 0; --i) {
            int count = 1;
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                count += right[s.top()];
                s.pop();
            }
            right[i] = count;
            s.push(i);
        }
    
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res = (res + (long long)arr[i] * left[i] * right[i]) /* % MOD */;
        }
    
        return (int)res;
    }
};
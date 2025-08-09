class Solution {
  public:
    int getLongestPrefix(string &s) {
        int n = s.size();
        if (n <= 1) return -1;
    
        // Compute Z-array
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            if (i <= r) z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
            if (i + z[i] - 1 > r) { l = i; r = i + z[i] - 1; }
        }
    
        // Find largest L (proper prefix) such that z[L] >= n - L
        for (int L = n - 1; L >= 1; --L) {
            if (z[L] >= n - L) return L;
        }
        return -1;

    }
};

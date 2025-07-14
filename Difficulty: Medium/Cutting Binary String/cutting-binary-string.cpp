class Solution {
  public:
    int solve(int i, string &s, unordered_set<int> &st, vector<int> &dp)
    {
        if(i == s.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int ans = s.size() + 1, num = 0;
        
        for(int j = i; j < s.size(); j++)
        {
            num = num * 2 + (s[j] - '0');
            if(s[i] != '0' && st.count(num))
            ans = min(ans, 1 + solve(j + 1, s, st, dp));
        }
        
        return dp[i] = ans;
    }
    int cuts(string s) {
        // code here
        if(s[0] == '0') return -1;
        
        unordered_set<int> st;
        for(int i = 1; i <= 1e9; i *= 5) st.insert(i);
        
        vector<int> dp(s.size(), -1);
        
        int ans = solve(0, s, st, dp);
        return ans > s.size() ? -1 : ans;
    }
};
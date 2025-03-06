//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int LCS(int i, int j, string &s1, string &s2, int dp[1001][1001])
    {
        if(i >= s1.size() || j >= s2.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = 1 + LCS(i + 1, j + 1, s1, s2, dp);
        else return dp[i][j] = max(LCS(i, j + 1, s1, s2, dp), LCS(i + 1, j, s1, s2, dp));
    }
    
    int longestPalinSubseq(string &s) {
        // code here
        int n = s.size();
        string str = s;
        reverse(str.begin(), str.end());
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return LCS(0, 0,s, str, dp);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int LCS(int i, int j, string &s1, string &s2, int dp[1001][1001])
    {
        if(i >= s1.size() || j >= s2.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = 1 + LCS(i + 1, j + 1, s1, s2, dp);
        else return dp[i][j] = max(LCS(i, j + 1, s1, s2, dp), LCS(i + 1, j, s1, s2, dp));
    }
    
    int lcs(string &s1, string &s2) {
        // code here
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return LCS(0, 0, s1, s2, dp);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
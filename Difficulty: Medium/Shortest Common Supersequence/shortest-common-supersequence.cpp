//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // Function to find length of shortest common supersequence of two strings.
    int solve(string &s1, string &s2, int n, int m, int t[501][501])
    {
        if(m == 0 || n == 0) return n + m;
        if(t[n][m] != -1) return t[n][m];
        
        if(s1[n - 1] == s2[m - 1])
        {
            return t[n][m] = 1 + solve(s1, s2, n - 1, m - 1, t);
        }
        else return t[n][m] = 1 + min(solve(s1, s2, n - 1, m, t), solve(s1, s2, n, m - 1, t));
        
        return 0;
    }
    
    
    int shortestCommonSupersequence(string &s1, string &s2) {
        // code here
        int n = s1.size(), m = s2.size();
        int t[501][501];
        memset(t, -1, sizeof(t));
        return solve(s1, s2, n, m, t);
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    // taking total testcases
    cin >> t;
    while (t--) {
        string X, Y;
        // taking String X and Y
        cin >> X >> Y;

        // calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y) << endl;
    }
    return 0;
}

// } Driver Code Ends
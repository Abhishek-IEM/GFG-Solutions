//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& coins, int sum, int i, int dp[1001][1001])
    {
        if(sum < 0 || i == coins.size()) return 0;
        
        if(sum == 0) return 1;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int pick = solve(coins, sum - coins[i], i, dp);
        int nopick = solve(coins, sum, i + 1, dp);
        
        return dp[i][sum] = pick + nopick;
    }
    
    int count(vector<int>& coins, int sum) {
        // code here.
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return solve(coins, sum, 0, dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
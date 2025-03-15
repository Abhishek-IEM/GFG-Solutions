//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
    int solve(vector<int> &coins, int sum, vector<int> &dp)
    {
        if(sum < 0) return INT_MAX;
        if(sum == 0) return 0;\
        
        if(dp[sum] != -1) return dp[sum];
        
        int mini = INT_MAX;
        
        for(int i = 0; i < coins.size(); i++)
        {
            int ans = solve(coins, sum - coins[i], dp);
            if(ans != INT_MAX) mini = min(mini, 1 + ans);
        }
        
        dp[sum] = mini;
        
        return dp[sum];
    }
    
    int minCoins(vector<int> &coins, int sum) {
        // Your code goes here
        vector<int> dp(sum + 1, -1);
        int result = solve(coins, sum, dp);
        return (result == INT_MAX) ? -1 : result;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
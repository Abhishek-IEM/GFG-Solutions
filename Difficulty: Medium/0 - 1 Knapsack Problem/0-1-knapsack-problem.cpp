//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int W, vector<int> &val, vector<int> &wt, int dp[1001][1001], int i) {
        if(i == wt.size()) return 0;
        
        if(dp[i][W] != -1) return dp[i][W];
        
        int pick = 0;
        
        if(W >= wt[i]) pick = val[i] + solve(W - wt[i], val, wt, dp, i + 1);
        
        int nopick =  solve(W, val, wt, dp, i + 1);
        
        return dp[i][W] = max(pick, nopick);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return solve(W, val, wt, dp, 0);
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
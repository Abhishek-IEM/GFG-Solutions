//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    bool solve(vector<int>& arr, int target, int i, vector<vector<int>>& dp)
    {
        if(target == 0) return 1;
        if(target < 0 || i == arr.size()) return 0;
        
        if(dp[i][target] != -1) return dp[i][target];
        
        bool pick = solve(arr, target - arr[i], i + 1, dp);
        bool nopick = solve(arr, target, i + 1, dp);
        
        return dp[i][target] = pick || nopick;
    }
    
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(arr, target, 0, dp);
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
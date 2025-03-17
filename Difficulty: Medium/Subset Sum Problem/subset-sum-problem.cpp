//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(vector<int>& arr, int sum, int i, vector<vector<int>> &dp)
    {
        if(sum == 0) return 1;
        if(sum < 0 || i == arr.size()) return 0;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int take = solve(arr, sum - arr[i], i + 1, dp);
        int notake = solve(arr, sum, i + 1, dp);
        
        return dp[i][sum] = take || notake;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1, -1));
        return solve(arr, sum, 0, dp);
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
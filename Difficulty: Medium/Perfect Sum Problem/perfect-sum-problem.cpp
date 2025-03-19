//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr, int target, int i, vector<vector<int>> &dp)
    {
        if(target == 0) return 1;
        if(i == arr.size()) return 0;
        
        if(dp[i][target] != -1) return dp[i][target];
        
        int notake = solve(arr, target, i + 1, dp);
        
        int take = 0;
        if (arr[i] <= target) {
            take = solve(arr, target - arr[i], i + 1, dp);
        }
        
        return dp[i][target] = take + notake;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size(), zero = 0;
        vector<int> newArr;
        for(int num : arr)
        {
            if(num == 0) zero++;
            else newArr.push_back(num);
        }
        vector<vector<int>> dp(newArr.size(),vector<int> (target + 1, -1));
        int subset = solve(newArr, target, 0, dp);
        return subset * pow(2, zero);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends
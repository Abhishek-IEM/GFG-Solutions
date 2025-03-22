//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int> &arr, int i, vector<int> &dp)
    {
        if(i >= arr.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int loot = arr[i] + solve(arr, i + 2, dp);
        int noloot = solve(arr, i + 1, dp);
        
        return dp[i] = max(loot, noloot);
    }
    
    
    int maxValue(vector<int>& arr) {
        // your code here
        int n = arr.size();
        
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        
        vector<int> case1(arr.begin(), arr.end() - 1); // Exclude last house
        vector<int> case2(arr.begin() + 1, arr.end()); // Exclude first house
        
        return max(solve(case1, 0, dp1), solve(case2, 0, dp2));
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
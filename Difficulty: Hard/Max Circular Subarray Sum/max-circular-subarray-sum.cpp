//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        // your code here
        int maxSum = INT_MIN, minSum = INT_MAX, n = arr.size();
        int s1 = 0, s2 = 0, totalSum = 0;
        for(int i = 0; i < n; i++)
        {
            totalSum += arr[i];
            s1 += arr[i];
            s2 += arr[i];
            if(s1 < 0) s1 = 0; //maximum Sum
            if(s2 > 0) s2 = 0; //minimum Sum
            maxSum = max(maxSum, s1);
            minSum = min(minSum, s2);
        }
        return max(maxSum, totalSum - minSum);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    // arr: input array
    int equilibriumPoint(vector<long long> &arr) {
        // Your code here
        int totalSum = 0, leftSum = 0, rightSum = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            totalSum += arr[i];
        }
        for(int i = 0; i < n; i++)
        {
            if(leftSum == (totalSum - leftSum - arr[i])) return i + 1;
            else leftSum += arr[i];
        }
        return -1;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<long long> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.equilibriumPoint(arr) << endl;
    }
}
// } Driver Code Ends